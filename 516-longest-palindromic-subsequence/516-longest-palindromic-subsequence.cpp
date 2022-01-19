class Solution {
public:
    int dp[1007][1007];
    int solveIt(string &str, int low, int high) {
        
        if (low == high) return 1;
        
        if (low > high) return 0;
        
        if(dp[low][high] != -1) return dp[low][high];
        
        int p = 1, q = 1;
        if(str[low] == str[high])
            p = 2 + solveIt(str, low + 1, high - 1);
        else
            q = max(solveIt(str, low + 1, high), solveIt(str, low, high - 1));
        
        return dp[low][high] = max(p, q);
    }
    int longestPalindromeSubseq(string s) {
        memset(dp, -1, sizeof dp);
        return solveIt(s, 0, s.length());
    }
};