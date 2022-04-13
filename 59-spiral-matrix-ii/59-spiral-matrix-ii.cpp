class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int num = 1;
        int i = 0;
        vector<vector<int>> matrix(n, vector<int> (n));
        while (num <= n * n) {
            
            int j = i;
            while(j < n - i)
                matrix[i][j++] = num++;
            
            j = i + 1;
            while(j < n - i)
                matrix[j++][n - 1 - i] = num++;
            
            j = n - 2 - i;
            while(j >= i)
                matrix[n - i - 1][j--] = num++;

            j = n - 2 - i;
            while (j > i)
                matrix[j--][i] = num++;
            
            i++;
        }
        
        return matrix;
    }
};