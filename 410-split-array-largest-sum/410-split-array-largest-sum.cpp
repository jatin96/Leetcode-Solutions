class Solution {
public:
    
    bool predicate(int maxSum, vector<int>& nums, int splits) {
        int currSum = 0;
        
        int cnt = 1;
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] > maxSum) return false;
            if (currSum + nums[i] > maxSum) {
                currSum = nums[i];
                cnt++;
            } else { 
                currSum += nums[i];
            }
        }
        
        if (cnt <= splits)
            return true;
        
        return false;
    }
    int splitArray(vector<int>& nums, int m) {
        int low = 0, high = accumulate(nums.begin(), nums.end(), 0);
        
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (predicate(mid, nums, m)) {
                high = mid - 1;
                ans = mid;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};