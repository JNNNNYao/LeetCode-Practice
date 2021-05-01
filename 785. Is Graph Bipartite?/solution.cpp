class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(color[i] == 0){
                color[i] = 1;
                q.push(i);
                while(!q.empty()){
                    int curr = q.front();
                    q.pop();
                    for(auto neighbor: graph[curr]){
                        if(color[neighbor] == color[curr]){
                            return false;
                        }
                        if(color[neighbor] == 0){
                            color[neighbor] = 3-color[curr];
                            q.push(neighbor);
                        }
                    }
                }
            }
        }
        return true;
    }
};