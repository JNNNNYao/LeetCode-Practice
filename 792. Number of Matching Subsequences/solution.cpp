class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<pair<int, int>>> mapping;    // pair(index of word, number of matched char)
        for (int i = 0; i < words.size(); i++) {
            mapping[words[i][0]].push_back(make_pair(i, 0));
        }
        int ans = 0;
        for (auto c: s) {
            if (mapping.find(c) != mapping.end()) { // important to reduce runtime
                vector<pair<int, int>> temp = mapping[c];
                mapping.erase(c);
                for (auto pair: temp) {
                    if (pair.second+1 == words[pair.first].size()) {
                        ans += 1;
                    }
                    else {
                        mapping[words[pair.first][pair.second+1]].push_back(make_pair(pair.first, pair.second+1));
                    }
                }
            } 
        }
        return ans;
    }
};