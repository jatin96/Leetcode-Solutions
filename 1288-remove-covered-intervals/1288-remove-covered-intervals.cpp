class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        set<vector<int>> res;
        
        for (int i = 0; i < n; i++) {
            bool flag = false;
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                
                if (intervals[j][0] <= intervals[i][0] && intervals[i][1] <= intervals[j][1]) {
                    flag = true;
                }
            }
            
            if(!flag)
                res.insert(intervals[i]);
        }
        
        return res.size();
    }
};