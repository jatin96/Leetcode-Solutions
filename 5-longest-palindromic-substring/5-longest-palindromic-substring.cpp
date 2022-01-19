class Solution {
public:
    string longestPalindrome(string str) {
        
        
        bool dp[1007][1007] = { false };
        
        int len = str.length();
        
        for (int i = 1; i <= len; i ++) {
            for (int j = 0; j < len - i + 1; j++) {
                if(i == 1) {
                    dp[j][j] = true;
                }
                else if ( i == 2) {
                    dp[j][j + 1] = str[j] == str[j + 1];
                }
                else {
                    dp[j][j + i - 1] = dp[j + 1][j + i - 2] && str[j] == str[i + j - 1];
                }
            }
        }
        
        int res = 1, posx = 0, posy = 0;
        
        for (int i = 0; i < len; i++) {
            for(int j = i; j < len; j++) {
                if(dp[i][j]) {
                    if(j - i + 1 > res) {
                        res = j - i + 1;
                        posx = i;
                        posy = j;
                    }
                }
            }
        }
        
        return str.substr(posx, posy - posx + 1);
        
    }
};