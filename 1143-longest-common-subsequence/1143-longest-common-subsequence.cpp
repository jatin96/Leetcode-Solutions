class Solution {
public:
    int n, m;
    int dp[1007][1007];
    int solveIt(string &str1, string &str2, int idx1, int idx2) {
        if(idx1 >= n || idx2 >= m)
            return 0;
        
        if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
        
        int p = 0, q = 0;
        if (str1[idx1] == str2[idx2])
            return dp[idx1][idx2] = 1 + solveIt(str1, str2, idx1 + 1, idx2 + 1);
        
            return dp[idx1][idx2] = max(solveIt(str1, str2, idx1 + 1, idx2), solveIt(str1, str2, idx1, idx2 + 1));
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        n = text1.length();
        m = text2.length();
        memset(dp, -1, sizeof dp);
        return solveIt(text1,text2,0,0);
    }
};