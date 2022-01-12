class Solution {
    private int dp[] = new int[101];
    private boolean isSingleDigitPossible(char ch) {
        
        if(ch != '0')
            return true;
        
        return false;
    }
    
    private boolean isDoubleDigitPossible(char ch1, char ch2) {
        if(ch1 == '1')
            return true;
        
        if(ch1 == '2' && ch2 >= '0' && ch2 <= '6')
            return true;
        
        return false;
    }
    
    int solveIt(String str, int idx, int n) {
        if(idx >= n)
            return 1;
        
        if(dp[idx] != -1)
            return dp[idx];
        
        int p = 0, q = 0;
        if(isSingleDigitPossible(str.charAt(idx)))
           p = solveIt(str, idx + 1, n);
        
        if(idx + 1 < n && isDoubleDigitPossible(str.charAt(idx), str.charAt(idx + 1)))
           q = solveIt(str, idx + 2, n);
           
        return dp[idx] = p + q;
    }
    public int numDecodings(String s) {
        Arrays.fill(dp, -1);
        return solveIt(s, 0, s.length());
    }
}