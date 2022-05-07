class Solution {
public:
    
    bool isOverlap(int a, int b, int x, int y) {
        return (min(b,y) - max(a, x)) >= 0;
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        int start = intervals[0][0];
        int end = intervals[0][1];
        
        vector<vector<int>> res;
        
        for (int i = 1; i < intervals.size(); i++) {
            int x = intervals[i][0];
            int y = intervals[i][1];
            
            if (isOverlap(start, end, x, y)) {
                start = min(x, start);
                end = max(y, end);
            } else {
                res.push_back({start, end});
                start = x;
                end = y;
            }
        }
        
        res.push_back({start, end});
        return res;
    }
};