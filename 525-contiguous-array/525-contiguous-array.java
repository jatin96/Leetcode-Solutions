class Solution {
    public int findMaxLength(int[] nums) {
        int n = nums.length;
        HashMap<Integer, Integer> hm = new HashMap<>();
        hm.put(0, -1);
        
        int res = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i] == 1 ? 1 : -1;
            if (hm.containsKey(sum))
                res = Math.max(res, i - hm.get(sum));
            else
                hm.put(sum, i);
        }
        
        return res;
        
    }
}