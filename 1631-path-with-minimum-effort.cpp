class Solution {
public:
    static const int INF = 1e7;
    static const int N_dir = 4;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int n, m;
    struct CustomCompare
    {
        bool operator()(const pair<int, pair<int, int>>& a, pair<int, pair<int, int>> &b) {
            return a.first < b.first;
        }
    };
    bool cmp(const pair<int, pair<int, int>>& a, pair<int, pair<int, int>> &b) {
        return a.first < b.first;
    }
    bool isValid(int x, int y) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        n = heights.size();
        m = heights[0].size();
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> Q;
        Q.push({0, 0, 0});
        
        int minEffort[101][101];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                minEffort[i][j] = INF;
        
        minEffort[0][0] = 0;
        
        while(!Q.empty()) {
            int weight = Q.top()[0];
            int x = Q.top()[1];
            int y = Q.top()[2];
            Q.pop();
            
            if(x == n - 1 && y == m - 1)
                return minEffort[x][y];
            
            
            if(minEffort[x][y] < weight)
                continue;
            
            
            for(int i = 0; i < N_dir; i++) {
                int x1 = x + dx[i];
                int y1 = y + dy[i];
               
                
                if (isValid(x1, y1) && minEffort[x1][y1] > max(abs(heights[x1][y1] - heights[x][y]), weight)) {
                    minEffort[x1][y1] = max(abs(heights[x1][y1] - heights[x][y]), weight);
                    Q.push({max(abs(heights[x1][y1] - heights[x][y]), weight), x1, y1});
                }
            }
        }
        
        return 0;
        
    }
};