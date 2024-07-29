class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int stops) {
    vector<vector<pair<int, int>>> gph(n);
    for (const auto& flight : flights) {
        int u = flight[0];
        int v = flight[1];
        int d = flight[2];
        gph[u].push_back({v, d});
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.push({0, {src, 0}});
    
    // Use a vector to store the minimum cost to reach each node with at most k stops
    vector<vector<int>> dist(n, vector<int>(stops + 2, INT_MAX));
    dist[src][0] = 0;

    while (!pq.empty()) {
        auto [cost, pos] = pq.top();
        pq.pop();
        int node = pos.first;
        int k = pos.second;

        if (node == dst) return cost;

        if (k > stops) continue;

        for (const auto& [neighbor, price] : gph[node]) {
            int new_cost = cost + price;
            if (new_cost < dist[neighbor][k + 1]) {
                dist[neighbor][k + 1] = new_cost;
                pq.push({new_cost, {neighbor, k + 1}});
            }
        }
    }
    return -1;
}
};