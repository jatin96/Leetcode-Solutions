class Solution {
    public void nextPermutation(int[] nums) {
        
        int n = nums.length;
        
        int pos = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pos = i;
                break;
            }
        }
        
        if(pos == -1) {
            Arrays.sort(nums);
            return;
        }
        int pos2 = pos + 1;
        for (int i = n - 1; i >= pos + 1; i--) {
            if (nums[pos] < nums[i]) {
                pos2 = i;
                break;
            }
        }
        
        int tmp = nums[pos];
        nums[pos] = nums[pos2];
        nums[pos2] = tmp;
        
        Arrays.sort(nums, pos + 1, n);
         
    }
}