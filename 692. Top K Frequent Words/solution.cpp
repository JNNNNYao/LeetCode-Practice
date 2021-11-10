class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> table;
        for (auto s: words) {
            if (table.find(s) == table.end()) {
                table[s] = 1;
            }
            else {
                table[s]++;
            }
        }
        auto cmp = [](const pair<int, string> & i, const pair<int, string> & j) {
            if (i.first == j.first) {
                return i.second > j.second;
            }
            return i.first < j.first;
        };
        set<pair<int, string>, decltype(cmp)> s(cmp);
        for (auto entry: table) {
            s.insert(make_pair(entry.second, entry.first));
        }
        vector<string> ans;
        for (auto it = s.rbegin(); it != s.rend(); it++) {
            if (k-- > 0) {
                ans.push_back(it->second);
            }
            else {
                break;
            }
        }
        return ans;
    }
};