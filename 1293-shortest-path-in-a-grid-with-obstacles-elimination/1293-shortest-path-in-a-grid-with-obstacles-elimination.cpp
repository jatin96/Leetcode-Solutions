class Solution {
public:
    bool vis[50][50][2500];
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    int n, m;
    
    bool isValid(int x, int y) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        queue <pair<pair<int, int>, pair<int, int>>> Q;
        memset(vis, false, sizeof vis);
        n = grid.size();
        m = grid[0].size();
        
        Q.push({{0, 0}, {k, 0}});
        vis[0][0][k] = true;
        
        while (!Q.empty()) {
            int x = Q.front().first.first;
            int y = Q.front().first.second;
            int currK = Q.front().second.first;
            int currSteps = Q.front().second.second;
            Q.pop();
            
            if (x == n - 1 && y == m - 1)
                return currSteps;
            
            for (int i = 0; i < 4; i++) {
                int x1 = x + dx[i];
                int y1 = y + dy[i];
                
                if (isValid(x1, y1)) {
                    if (!vis[x1][y1][currK] && grid[x1][y1] == 0) {
                        Q.push({{x1, y1}, {currK, currSteps + 1}});
                        vis[x1][y1][currK] = true;
                    } else if (grid[x1][y1] == 1 && currK > 0 && !vis[x1][y1][currK - 1]) {
                        Q.push({{x1, y1}, {currK - 1, currSteps + 1}});
                        vis[x1][y1][currK - 1] = true;
                        
                    }
                }
            }
        }
        
        return -1;
    }
};