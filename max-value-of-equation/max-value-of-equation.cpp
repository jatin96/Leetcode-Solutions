class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue< pair<int, int>> Q;
        
        Q.push({points[0][1] - points[0][0], points[0][0]});
        
        int res = INT_MIN;
        for (int j = 1;j < points.size(); j++) {
            
            while (!Q.empty() && points[j][0] - Q.top().second > k)
                Q.pop();
            
            if(!Q.empty())
                res = max(res, points[j][0] + points[j][1] + Q.top().first);
            
            Q.push({points[j][1] - points[j][0], points[j][0]});
        }
        
        return res;
    }
};