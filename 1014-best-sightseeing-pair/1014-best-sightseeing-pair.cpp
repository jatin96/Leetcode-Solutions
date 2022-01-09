class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int i = 0;
        int maxi = values[i] + i;
        int res = -1;
        for (int j = 1; j < n; j++) {
            res = max(res, maxi + values[j] - j);
            maxi = max(maxi, values[j] + j);
        }
        
        return res;
    
    }
};