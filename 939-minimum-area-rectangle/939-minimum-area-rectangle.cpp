class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, bool> exists[50007];
        int n = points.size();
        for(int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y= points[i][1];
            exists[x][y] = true;
        }
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                
                if(x1 == x2 || y1 == y2) continue;
                
                if(exists[x1][y2] && exists[x2][y1]) {
                    res = min(res, abs(x1 - x2) * abs(y1 - y2));
                }
            }
        }
        
        return res == INT_MAX ? 0 : res;
    }
};