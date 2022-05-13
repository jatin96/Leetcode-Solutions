class Solution {
    private static final int MOD = 1_000_000_007;
    public int numMusicPlaylists(int n, int goal, int k) {
        return (int) dfs(n, goal, k, 0, 0, new HashMap<>());
    }
    
    private long dfs(int n, int goal, int k, int currentLen, int uniqueUsed, Map<String, Long> memo){
        if(currentLen == goal){
            return uniqueUsed == n ? 1 : 0;
        }
        
        String key = currentLen + ":" + uniqueUsed;
        if(memo.containsKey(key)){
            return memo.get(key);
        }
        
        long res = (dfs(n, goal, k, currentLen + 1, uniqueUsed, memo) 
                    * (Math.max(0, uniqueUsed - k))) % MOD;
        
        res = (res + dfs(n, goal, k, currentLen + 1, uniqueUsed + 1, memo) 
               * (n - uniqueUsed)) % MOD;
        
        memo.put(key, res);
        return res;
    }
}