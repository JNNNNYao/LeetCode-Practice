class Solution {
public:
    bool DFS(vector<vector<int>>& graph, vector<int>& state, vector<int>& finish, int curr) {
        state[curr] = 1;
        for(auto neighbor: graph[curr]){
            if(state[neighbor] == 1){
                return false;
            }
            else if(state[neighbor] == 0){
                if(!DFS(graph, state, finish, neighbor)){
                    return false;
                }
            }
        }
        finish.push_back(curr);
        state[curr] = 2;
        return true;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> state(numCourses, 0);
        vector<int> finish;
        vector<int> ans;
        for(auto it: prerequisites){
            graph[it[1]].push_back(it[0]);
        }
        for(int i = 0; i < numCourses; i++){
            if(state[i] == 0){
                if(!DFS(graph, state, finish, i)){
                    return vector<int>();
                }
            }
        }
        for(int i = numCourses-1; i >= 0; i--){
            ans.push_back(finish[i]);
        }
        return ans;
    }
};