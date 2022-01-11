class Solution {
public:
   int trap(vector<int>& height) {
        int n = height.size();
       
        if (n == 1 || n == 0)
            return 0;
        int left[100007], right[100007];
        left[0] = height[0];
        for(int i = 1; i < n; i++) {
            left[i] = max(left[i-1], height[i]);
        }
        right[n - 1] = height[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], height[i]);
        }
        int res = 0;
        for(int i = 1; i < n - 1; i++) {
            int x;
            if(i == 0)
                x = right[i + 1];
            else if(i == n - 1)
                x = left[i - 1];
            else
                x = min(left[i - 1], right[i + 1]);
            
            if(x > height[i])
                res = res + (x - height[i]);
        }
        return res;
}
};