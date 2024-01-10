class Solution {
public:
    void dfs(int start, int n, const std::vector<std::vector<int>>& roads,
             std::vector<int>& visited) {
        std::stack<int> s;
        s.push(start);

        while (!s.empty()) {
            int current = s.top();
            s.pop();

            if (!visited[current]) {
                visited[current] = 1; // Mark the current city as visited.

                // Iterate over all cities to find the ones connected to the
                // current city.
                for (int i = 0; i < n; i++) {
                    if (roads[current][i] && !visited[i]) {
                        // If city 'i' is connected to the current city and not
                        // visited, push it onto the stack.
                        s.push(i);
                    }
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& roads) {
        int n = roads[0].size();
        std::vector<int> visited(
            n, 0); // Create an array to track visited cities, initialized to 0.
        int count = 0; // Initialize the province count.
        // Iterate over all cities to find unvisited cities and perform DFS on
        // them.
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {

                // If city 'i' is unvisited, then it's part of a new province.
                // Perform iterative DFS to mark all connected cities in this
                // province as visited.
                dfs(i, n, roads, visited);

                // Increment the province count after DFS traversal.
                count++;
            }
        }

        // Return the total number of provinces.
        return count;
    }
};