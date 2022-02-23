class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int n = 2, m = 3;
    
    map <vector<vector<int>>, bool> vis;
    
    vector<vector<int>> board;
    
    bool isPuzzleSolved(vector<vector<int>>& board) {
        return board[0][0] == 1 && board[0][1] == 2 && board[0][2] == 3 && board[1][0] == 4 && board[1][1] == 5 && board[1][2] == 0;
    }
    
    bool isValid(int x, int y) {
        return x >= 0 && x < n && y>= 0 && y < m;
    }
    
    pair<int, int> findZero(vector<vector<int>>& board) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++){
                if (board[i][j] == 0)
                    return {i, j};
            }
        }
        
        return {-1, -1};
    }
    
    vector<vector<int>> getNextBoard(int x, int y, int x1, int y1, vector<vector<int>> &currBoard) {
        vector<vector<int>> newBoard(currBoard);
        int tmp = newBoard[x][y];
        newBoard[x][y] = newBoard[x1][y1];
        newBoard[x1][y1] = tmp;
        
        return newBoard;
    }
    
    int slidingPuzzle(vector<vector<int>>& board) {
        this -> board = board;
        
        queue<pair<vector<vector<int>>, int > > Q;
        
        Q.push({board, 0});
        
        while (!Q.empty()) {
            vector<vector<int>> currBoard = Q.front().first;
            int moves = Q.front().second;
            Q.pop();
            
            if (isPuzzleSolved(currBoard))
                return moves;
            
            auto [x, y] = findZero(currBoard);
            
            for (int i = 0; i < 4; i++) {
                int x1 = x + dx[i];
                int y1 = y + dy[i];
                
                if (isValid(x1, y1)) {
                     vector<vector<int>> nextBoard = getNextBoard(x, y, x1, y1, currBoard);
                
                if (vis.find(nextBoard) == vis.end())
                    Q.push({nextBoard, moves + 1});
                    vis[nextBoard] = true;
                }
            }
        }
        
        return -1;
    }
};