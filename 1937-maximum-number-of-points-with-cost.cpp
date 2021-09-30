class Solution {
public:
    int m, n;
    vector<vector<int>> points;
    long long res = 0;
    void solveIt(int row, vector<long long> &left, vector<long long> &right, vector<long long> &prev) {
        
        if( row == n) {
            for (int i = 0; i < m; i++) {
                res = max(res, prev[i]);
            }
    
            return ;
        }
  
        vector<long long> curr;
        for(int col = 0; col < m; col++) {
            curr.push_back(points[row][col] + max(left[col], right[col]));
        }
        
        
        left[0] = curr[0];
        right[m - 1] = curr[m - 1];
        
        for(int col = 1; col < m; col++)
            left[col] = max(left[col - 1] - 1, curr[col]);
            
        for(int col = m - 2; col >= 0; col--)
            right[col] = max(right[col + 1] - 1, curr[col]);
        
        solveIt(row + 1, left, right, curr);
        
        
    }
    long long maxPoints(vector<vector<int>>& points) {
        
        n = points.size();
        m = points[0].size();
        this -> points = points;
        
        vector<long long> left(m,0), right(m,0), prev(m,0);
        solveIt(0, left, right, prev);
        return res;
    }
};