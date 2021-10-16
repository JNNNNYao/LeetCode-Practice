class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> ans(m, vector<int>(n, 2147483647));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    ans[i][j] = 0;
                    q.push(make_pair(i, j));
                }
            }
        }
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            int step = ans[x][y];
            q.pop();
            if(x+1 <= m-1 && ans[x+1][y] > step+1){
                ans[x+1][y] = step+1;
                q.push(make_pair(x+1, y));
            }
            if(x-1 >= 0 && ans[x-1][y] > step+1){
                ans[x-1][y] = step+1;
                q.push(make_pair(x-1, y));
            }
            if(y+1 <= n-1 && ans[x][y+1] > step+1){
                ans[x][y+1] = step+1;
                q.push(make_pair(x, y+1));
            }
            if(y-1 >= 0 && ans[x][y-1] > step+1){
                ans[x][y-1] = step+1;
                q.push(make_pair(x, y-1));
            }
        }
        return ans;
    }
};