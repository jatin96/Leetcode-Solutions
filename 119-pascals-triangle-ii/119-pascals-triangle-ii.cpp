class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int numRows = rowIndex + 1;
        vector<vector<int>> res(numRows, vector<int> (numRows));
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j <= i; j++) {
                if (i == 0 || j == 0) {
                    res[i][j] = 1;
                }
                else {
                    res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
                }
            }
        }
        
        for (int i = 0; i < numRows; i++)
            res[i].resize(i + 1);
        
        return res[rowIndex];
    }
};