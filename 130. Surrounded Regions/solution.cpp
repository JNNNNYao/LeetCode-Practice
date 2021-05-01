class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            if(i == 0 || i == m-1){
                for(int j = 0; j < n; j++){
                    if(board[i][j] == 'O'){
                        q.push(make_pair(i, j));      
                    }
                }
            }
            else{
                if(board[i][0] == 'O'){
                    q.push(make_pair(i, 0));   
                }
                if(board[i][n-1] == 'O'){
                    q.push(make_pair(i, n-1));   
                }
            }
        }
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            board[x][y] = '!';
            if(x+1 <= m-1 && board[x+1][y] == 'O'){
                q.push(make_pair(x+1, y));
            }
            if(x-1 >= 0 && board[x-1][y] == 'O'){
                q.push(make_pair(x-1, y));
            }
            if(y+1 <= n-1 && board[x][y+1] == 'O'){
                q.push(make_pair(x, y+1));
            }
            if(y-1 >= 0 && board[x][y-1] == 'O'){
                q.push(make_pair(x, y-1));
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '!'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};