class Solution {
public:
    
    bool isOverlap(pair<int, int> a, pair<int, int> b) {
        return (min(a.second, b.second) - max(a.first, b.first)) > 0;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        
        int cnt = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (isOverlap({start, end}, {intervals[i][0], intervals[i][1]})) {
                if (intervals[i][1] <= end) {
                    start = intervals[i][0];
                    end = intervals[i][1];
                }
                
                cnt++;
            } else  {
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        
        return cnt;
    }
};