class Solution {
public:

    void merge(vector<pair<int, string>>& pairs, int s, int mid, int e){
        vector<pair<int, string>> temp;
        int l = s, r = mid + 1;
        while (l <= mid && r <= e) {
            if (pairs[l].first <= pairs[r].first) {
                temp.push_back(pairs[l]);
                l++;
            } else {
                temp.push_back(pairs[r]);
                r++;
            }
        }
        while (l <= mid) {
            temp.push_back(pairs[l]);
            l++;
        }
        while (r <= e) {
            temp.push_back(pairs[r]);
            r++;
        }
        for (int i = 0; i < temp.size(); i++) {
            pairs[s + i] = temp[i];
        }
    }

    void mergeSort(vector<pair<int, string>>& pairs, int s, int e){
        if (s >= e) return;
        int mid = s + (e - s) / 2;
        mergeSort(pairs, s, mid);
        mergeSort(pairs, mid + 1, e);
        merge(pairs, s, mid, e);
    }

    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int, string>> pairs;
        for (int i = 0; i < n; i++) {
            pairs.push_back({heights[i], names[i]});
        }
        mergeSort(pairs, 0, n - 1);
        vector<string> sortedNames;
        for (int i = n - 1; i >= 0; i--) { // reverse order to get descending height order
            sortedNames.push_back(pairs[i].second);
        }
        return sortedNames;
    }

};