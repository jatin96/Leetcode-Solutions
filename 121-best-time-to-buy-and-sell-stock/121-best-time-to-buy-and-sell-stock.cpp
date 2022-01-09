class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int maxi_right[100007] = {0};
        
        for (int i = n - 1; i >= 0; i--) {
            maxi_right[i] = max(maxi_right[i + 1], prices[i]);
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            res = max(res, maxi_right[i + 1] - prices[i]);
        }
        
        return res;
    }
};