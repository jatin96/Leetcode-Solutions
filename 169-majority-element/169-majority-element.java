class Solution {
    public int majorityElement(int[] nums) {
        int n = nums.length;
        
        int cnt = 1;
        int res = nums[0];
        
        for (int i = 1; i < n; i++) {
            if (res == nums[i]) {
                cnt++;
            }
            else
            {
                cnt--;
                if (cnt == 0) {
                    cnt = 1;
                    res = nums[i];
                }
            }
        }
        
        return res;
    }
}