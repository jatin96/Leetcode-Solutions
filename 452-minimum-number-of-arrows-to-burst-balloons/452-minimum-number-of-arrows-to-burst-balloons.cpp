class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        
        for (int i = 0; i < points.size(); i++){
            cout << points[i][0] << " " << points[i][1] << endl;
        }
        int cnt = 0, high = 0, low = 0;
        for (int i = 0; i < points.size(); i++) {
            if (i == 0) {
                low = points[i][0];
                high = points[i][1];
                cnt = 1;
                continue;
            }
            
            if (points[i][0] > high) {
                cnt++;
                high = points[i][1];
                low = points[i][0];
            } else {
                low = max(low, points[i][0]);
                high = min(high, points[i][1]);
            }
        }
        
        return cnt;
    }
};