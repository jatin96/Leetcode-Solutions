class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> leftMax(n, 0), rightMin(n, 0);
        for (int i = 0; i < n; i++) {
            leftMax[i] = i == 0 ? arr[0] : max(leftMax[i - 1], arr[i]);
            int j = n - 1 - i;
            rightMin[j] = j == n - 1 ? arr[j] : min(rightMin[j + 1], arr[j]); 
        }
        
        int res = 1;
        for (int i = 0; i < n - 1; i++) {
            if (leftMax[i] <= rightMin[i + 1])
                res++;
        }
        
        return res;
    }
};