class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        
        int low = points[0][0], high = points[0][1], res = 1, n = points.size();
        for (int i = 1; i < n; i++) {
            int xstart = points[i][0];
            int xend = points[i][1];
            
            if (xstart >= low && xstart <= high) {
                low = max(xstart, low);
                high = min(xend, high);
            } else {
                low = xstart;
                high = xend;
                res++;
            }
        }
        
        return res;
    }
};