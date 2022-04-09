class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = nums[0] + nums[1] + nums[2];
        
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;
            while ( j < k) {
                int curr_sum = nums[i] + nums[j] + nums[k];
                if(curr_sum == target)
                    return curr_sum;
                if(abs(curr_sum - target) < abs(res - target)) {
                    res = curr_sum;
                }

                if(curr_sum > target) {
                    k--;
                }
                
                if(curr_sum < target) {
                    j++;
                }
            }
        }
        
        return res;
    }
};