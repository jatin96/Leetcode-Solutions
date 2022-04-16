class Solution {
public:
    int n;
    int M = 1000000007;
    vector<vector<int>> colorCombinations;
    
    int dp[5001][4][4][4];
    
    void generateColorCombinations() {
        for (int i = 1; i <= 3; i ++)
            for (int j = 1; j <= 3; j++)
                for (int k = 1; k <= 3; k++) {
                    if (i == j || j == k)
                        continue;
                    colorCombinations.push_back({i, j, k});
                }   
    }
    
    int solveIt(int idx, int col0, int col1, int col2) {
        
        if(idx == n)
            return 1;
        
        if (dp[idx][col0][col1][col2] != -1) return dp[idx][col0][col1][col2];
        
        int res = 0;
        for (int i = 0; i < colorCombinations.size(); i++) {
            int currCol0 = colorCombinations[i][0];
            int currCol1 = colorCombinations[i][1];
            int currCol2 = colorCombinations[i][2];
            
            if (currCol0 == col0 || currCol1 == col1 || currCol2 == col2)
                continue;
            
            res = (res + solveIt(idx + 1, currCol0, currCol1, currCol2)) % M;
        }
        
        return dp[idx][col0][col1][col2] = res;
    }
    int numOfWays(int n) {
        this -> n = n;
        generateColorCombinations();
        memset(dp, -1, sizeof dp);
        return solveIt(0, 0, 0, 0);
    }
};