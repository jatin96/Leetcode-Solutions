class Solution {
public:
    
    bool isOverlap(int x1, int y1, int x2, int y2) {
        return (min(y1, y2) - max(x1, x2)) >= 0;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        
        if (n == 1) 
            return intervals;
        
        vector<vector<int>> res;
        int min_x, max_y;
        for (int i = 1; i < n; i++) {
            int x1 = intervals[i - 1][0];
            int y1 = intervals[i - 1][1];
            
            min_x = x1, max_y = y1;
            while (i < n && isOverlap(min_x, max_y, intervals[i][0], intervals[i][1])) {
                min_x = min(min_x, intervals[i][0]);
                max_y = max(max_y, intervals[i][1]);
                i++;
            }
            
            cout << min_x  << ", " << max_y << endl;
            res.push_back({min_x, max_y});
        }
        
        if (!isOverlap(min_x, max_y, intervals[n - 1][0], intervals[n - 1][1]))
            res.push_back({intervals[n - 1][0], intervals[n - 1][1]});
        
        return res;
        
    }
};