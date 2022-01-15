class Solution {
public:
    bool isOverlap(int x1, int y1, int x2, int y2) {
        if (y1 < x2)
            return false;
        if (y2 < x1)
            return false;
        
        return true;
            
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        set<int> overlaps{newInterval[0], newInterval[1]};
        set<int> overlapIndex;
        
        for (int i = 0; i < n; i++) {
            if (isOverlap(intervals[i][0], intervals[i][1], newInterval[0], newInterval[1])) {
                overlaps.insert(intervals[i][0]);
                overlaps.insert(intervals[i][1]);
                overlapIndex.insert(i);
            }
        }
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            if (overlapIndex.find(i) == overlapIndex.end())
                res.push_back(intervals[i]);
        }
        
        res.push_back({*overlaps.begin(), *overlaps.rbegin()});
        
        sort(res.begin(), res.end());
        
        return res;
    }
};