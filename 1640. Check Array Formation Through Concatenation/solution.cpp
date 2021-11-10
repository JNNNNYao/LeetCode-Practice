class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, vector<int>> table;
        for (auto a: pieces) {
            table[a[0]] = a;
        }
        int idx = 0;
        while (true) {
            auto entry = table.find(arr[idx]);
            if (entry != table.end()) {
                for (int j = 0; j < entry->second.size(); j++) {
                    if (arr[idx] == entry->second[j]) {
                        idx++;
                        if (idx == arr.size()) {
                            if (j == entry->second.size()-1) {
                                return true;
                            }
                            else {
                                return false;
                            }
                        }
                    }
                    else {
                        return false;
                    }
                }
            }
            else {
                return false;
            }
        }
        return true;
    }
};