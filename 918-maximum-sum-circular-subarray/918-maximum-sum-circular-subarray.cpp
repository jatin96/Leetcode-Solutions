class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int localMax = nums[0];
        int globalMax = nums[0];
        int localMin = nums[0];
        int globalMin = nums[0];
        int sum = nums[0];
        int cnt = nums[0] < 0 ? 1: 0;
        int maxi = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            localMax = max(nums[i], localMax + nums[i]);
            globalMax= max(globalMax, localMax);
            localMin = min(nums[i], localMin + nums[i]);
            globalMin = min(globalMin, localMin);
            sum += nums[i];
            if(nums[i] < 0)
                cnt++;
            maxi = max(maxi, nums[i]);
        }
                
        if(cnt == nums.size())
            return maxi;
        
        return max(globalMax, sum - globalMin);
    }
};