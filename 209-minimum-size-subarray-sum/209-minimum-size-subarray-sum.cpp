class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int currSum = 0;
        int numsSize = nums.size();
        int right = 0, left = 0, res = INT_MAX;
        
        while (right < numsSize) {
            currSum = currSum + nums[right];
            right++;
            
            while (currSum - nums[left] >= target)
                currSum -= nums[left++];
            
            if(currSum >= target)
            res = min(res, right - left);
        }
        
        if (res == INT_MAX) return 0;
        return res;
        
    }
};