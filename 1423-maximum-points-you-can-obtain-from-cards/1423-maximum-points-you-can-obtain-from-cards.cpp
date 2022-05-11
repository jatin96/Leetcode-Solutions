class Solution {
public:
    
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int cumm_sum[100007];
        
        cumm_sum[0] = cardPoints[0];
        
        
        for(int i = 1; i < n; i++) cumm_sum[i] = cumm_sum[i - 1] + cardPoints[i];
        
        if(k == n) 
            return cumm_sum[n - 1];
        
        int res = 0;
        for(int i = 0; i <= k; i ++)
            res = max(res, (cumm_sum[n - 1] - cumm_sum[n - 1 - (k - i)]) + (i == 0 ? 0 : cumm_sum[i - 1]));
        
        return res;
    }
};