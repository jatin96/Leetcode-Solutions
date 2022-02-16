class Solution {
    public List<Integer> goodDaysToRobBank(int[] security, int time) {
        int n = security.length;
        int[] left = new int[n];
        int[] right = new int[n];
        List<Integer> res = new ArrayList<>();
        
        if (time == 0) {
            for (int i = 0; i < n; i++){
                res.add(i);
            }
            
            return res;
        }
        
        if (n == 1)
            return Arrays.asList();
        
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                left[i] = 1;
                continue;
            }
            if (security[i - 1] >= security[i])
                left[i] = left[i - 1] + 1;
            else
                left[i] = 1;
        }
        
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                right[i] = 1;
                continue;
            }
            
            if (security[i] <= security[i + 1])
                right[i] = right[i + 1] + 1;
            else
                right[i] = 1;
        }
        
        
        
        for (int i = 1; i < n - 1; i++) {
            
            int val = Math.min(left[i - 1], right[i + 1]);
            
            if (val >= time && security[i - 1] >= security[i] && security[i] <= security[i + 1])
                res.add(i);
        }
        
        return res;
    }
}