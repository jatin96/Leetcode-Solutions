class NumMatrix {
    int[][] cumm_matrix;
    int n, m;
    public NumMatrix(int[][] matrix) {
        n = matrix.length;
        m = matrix[0].length;
        
        cumm_matrix = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(i == 0 && j == 0)
                    cumm_matrix[i][j] = matrix[i][j];
                else if(i == 0) 
                    cumm_matrix[i][j] = cumm_matrix[i][j - 1] + matrix[i][j];
                else if(j == 0)
                    cumm_matrix[i][j] = cumm_matrix[i - 1][j] + matrix[i][j];
                else
                    cumm_matrix[i][j] = cumm_matrix[i][j - 1] + 
                                        cumm_matrix[i - 1][j] - 
                                        cumm_matrix[i - 1][j - 1] + 
                                        matrix[i][j]; 
            }
        }
    }
    
    public int sumRegion(int row1, int col1, int row2, int col2) {
        
        
        if(row1 == 0 && col1 == 0)
            return (cumm_matrix[row2][col2]);
        else if(row1 == 0)
            return (cumm_matrix[row2][col2] - cumm_matrix[row2][col1 - 1]);
        else if(col1 == 0)
            return (cumm_matrix[row2][col2] - cumm_matrix[row1 - 1][col2]);
        
        
        return (
            cumm_matrix[row2][col2] -
            cumm_matrix[row1 - 1][col2] -
            cumm_matrix[row2][col1 - 1] +
            cumm_matrix[row1 - 1][col1 - 1]
        );
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */