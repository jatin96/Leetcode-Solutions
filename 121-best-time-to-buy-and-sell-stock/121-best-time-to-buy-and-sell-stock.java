class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[] maxProfitDay = new int[n];
        Arrays.fill(maxProfitDay, 0);
        
        maxProfitDay[n - 1] = prices[n - 1];
        for (int i = n - 2; i >= 0; i--)
            maxProfitDay[i] = Math.max(maxProfitDay[i + 1], prices[i]);
        
        int res = 0;
        
        for (int i = 0; i < n - 1; i++) {
            int buyPrice = prices[i];
            int sellPrice = maxProfitDay[i + 1];
            
            if (sellPrice - buyPrice > res)
                res = sellPrice - buyPrice;
        }
        
        return res;
    }
}