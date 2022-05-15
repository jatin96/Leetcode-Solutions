class Solution {
    typedef pair<int, pair<int , int >> pii;
    int INF = 10000000;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
public:
    bool isValid(int x, int y, int n) {
        return (x >= 0 && x < n && y>= 0 && y < n);
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pii, vector<pii>, greater<pii>> priorityQueue;
        
        int n = grid.size();
        
        int leastTime[50][50];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                leastTime[i][j] = INF;
        
        
        priorityQueue.push({0, {0, 0}});
        leastTime[0][0] = 0;
        
        while (!priorityQueue.empty()) {
            int x = priorityQueue.top().second.first;
            int y = priorityQueue.top().second.second;
            int currLeastTime = priorityQueue.top().first;
            priorityQueue.pop();
            
            if (leastTime[x][y] < currLeastTime) continue;
            
            for (int i = 0; i < 4; i++) {
                int x1 = x + dx[i];
                int y1 = y + dy[i];
                if (isValid(x1, y1, n)) {
                    int timeDiff = max(grid[x][y], grid[x1][y1]);
                    if (max(leastTime[x][y], timeDiff) < leastTime[x1][y1]) {
                        priorityQueue.push({max(leastTime[x][y], timeDiff), {x1, y1}});
                        leastTime[x1][y1] = max(leastTime[x][y], timeDiff);
                    }
                }
            }
        }
        
        return leastTime[n - 1][n - 1]; 
    }
};