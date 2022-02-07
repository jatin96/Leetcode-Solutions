class Solution {

    public int longestSubarray(int[] nums, int limit) {
        int i = 0, j = 0, maxi = Integer.MIN_VALUE, mini = Integer.MAX_VALUE, n = nums.length;
        TreeSet<Integer> ts = new TreeSet<>();
        Map<Integer, Integer> hm = new HashMap<>();
        int res = 1;
        while (j < n) {
            
            ts.add(nums[j]);
            hm.put(nums[j], hm.getOrDefault(nums[j], 0) + 1);
            maxi = ts.last();
            mini = ts.first();
            
            while (i <= j && maxi - mini > limit) {
                if (hm.get(nums[i]) >= 2)
                    hm.put(nums[i], hm.get(nums[i]) - 1);
                else {
                    hm.put(nums[i], 0);
                    ts.remove(nums[i]);
                }

                mini = ts.first();
                maxi = ts.last();
                i++;
            }
            
            if (maxi - mini <= limit)
                res = Math.max(res, j - i + 1);
                 
            j++;
        }
        
         if (maxi - mini <= limit)
                res = Math.max(res, j - i);
        
        return res;
        
    }
}