class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int currSum = 0, left = 0;
        int dp[100007] = {};
        
        for (int i = 0; i < arr.size(); i++) dp[i] = INT_MAX;
        
        int right = 0, len = INT_MAX;
        int res = INT_MAX;
        while(right < arr.size()) {
            while (left < arr.size() && currSum + arr[right] > target) {
                currSum -= arr[left];
                left++;
            }
            
            currSum += arr[right];
            
            if (currSum == target) {
                if (left > 0 && dp[left - 1] != INT_MAX) {
                    res = min(res, right - left + 1 + dp[left - 1]);
                }
                
                len = min(len, right - left + 1);
            }
            dp[right] = len;
            right++;
        }
        
        return res >= INT_MAX ? -1 : res;
    }
};