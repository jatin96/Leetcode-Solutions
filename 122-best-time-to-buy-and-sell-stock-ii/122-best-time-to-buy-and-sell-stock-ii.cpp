class Solution {
public:
       int maxProfit(vector<int>& A) {
        int res = 0;
        for (int i = 1; i < A.size(); ++i)
            res += max(A[i] - A[i - 1], 0);
        return res;
    }
};