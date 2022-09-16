class Solution {
public:
    static const int N = 1007;
    long long dp[N][N];
    int offset;
    int m, n;
    void initialize(vector<int> &multipliers, vector<int> &nums) {
    m = multipliers.size();
    n = nums.size();   
    
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                dp[i][j] = LONG_MIN;
        
    }
    
    long long solveIt(int idx, int low, int high, vector<int> &nums, vector<int> & multipliers) {
        if (idx == m + 1)
            return 0;
        
        if (dp[low][high + offset] != LONG_MIN)
            return dp[low][high + offset];
        
        long long p = (long long)multipliers[idx - 1] * nums[low  - 1] + solveIt(idx + 1, low + 1, high, nums, multipliers);
        long long q = (long long)multipliers[idx - 1] * nums[high - 1] + solveIt(idx + 1, low, high - 1, nums, multipliers);
        return dp[low][high + offset] = max(p, q);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        
        initialize(multipliers, nums);
        
        offset =  m - n;
        
        for (int i = 0; i < m; i++)
            cout << multipliers[i] << " " << endl;
        
        return solveIt(1, 1, n, nums, multipliers);
    }
};