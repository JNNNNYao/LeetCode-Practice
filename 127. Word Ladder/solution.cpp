class Solution {
public:
    bool check(string s1, string s2) {
        int cnt = 0;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i]){
                cnt++;
                if(cnt > 1){
                    return false;
                }
            }
        }
        return true;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        bool notFound = true;
        
        queue<pair<string, int>> start;
        queue<pair<string, int>> end;
        vector<int> history(n, 2147483647);
        vector<bool> startVisit(n, false);
        vector<bool> endVisit(n, false);
        
        start.push(make_pair(beginWord, 0));
        end.push(make_pair(endWord, 0));
        
        for(int i = 0; i < n; i++){
            if(wordList[i] == endWord){
                history[i] = 0;
                endVisit[i] = true;
                notFound = false;
            }
            if(wordList[i] == beginWord){
                history[i] = 0;
                startVisit[i] = true;
            }
        }
        if(notFound){
            return 0;
        }
        
        for(int i = 0; i < n/2+1; i++){
            while(!start.empty() && start.front().second == i){
                string str = start.front().first;
                start.pop();
                for(int j = 0; j < n; j++){
                    if(!startVisit[j] && check(str, wordList[j])){
                        if(endVisit[j]){
                            return (i+1)+history[j]+1;
                        }
                        start.push(make_pair(wordList[j], i+1));
                        history[j] = i+1;
                        startVisit[j] = true;   
                    }
                }
            }
            while(!end.empty() && end.front().second == i){
                string str = end.front().first;
                end.pop();
                for(int j = 0; j < n; j++){
                    if(!endVisit[j] && check(str, wordList[j])){
                        if(startVisit[j]){
                            return (i+1)+history[j]+1;
                        }
                        end.push(make_pair(wordList[j], i+1));
                        history[j] = i+1;
                        endVisit[j] = true;   
                    }
                }
            }
        }
        return 0;
    }
};