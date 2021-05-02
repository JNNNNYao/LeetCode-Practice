class Solution {
private:
    map<string, vector<pair<string, double>>> adjList;
    
    double BFS(string start, string target) {
        if(adjList.find(start)==adjList.end() || adjList.find(target)==adjList.end()){
            return -1.0;
        }
        if(start == target){
            return 1.0;
        }
        set<string> visit;
        visit.insert(start);
        queue<pair<string, double>> q;
        q.push(make_pair(start, 1.0));
        while(!q.empty()){
            pair<string, double> curr = q.front();
            q.pop();
            string var = curr.first;
            double value = curr.second;
            for(auto it: adjList[var]){
                if(visit.find(it.first) == visit.end()){
                    if(it.first == target){
                        return value*it.second;
                    }
                    visit.insert(it.first);
                    q.push(make_pair(it.first, value*it.second));
                }
            }
        }
        return -1.0;
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i = 0; i < equations.size(); i++){
            string A = equations[i][0];
            string B = equations[i][1];
            adjList[A].push_back(make_pair(B, values[i]));
            adjList[B].push_back(make_pair(A, 1.0/values[i]));
        }
        vector<double> ans;
        for(int i = 0; i < queries.size(); i++){
            string C = queries[i][0];
            string D = queries[i][1];
            ans.push_back(BFS(C, D));
        }
        return ans;
    }
};