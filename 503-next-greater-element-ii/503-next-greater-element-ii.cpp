class Solution {
public:
    
    vector<int> getNextGreater(vector<int> &nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        
        stack<int> st;
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            
            if (!st.empty())
                res[i] = nums[st.top()];
            st.push(i);
        }
        
        res.resize(n / 2);
        return res;
    }
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> arr(nums);
        
        for (int i = 0; i < nums.size(); i++)
            arr.push_back(nums[i]);
        
        return getNextGreater(arr);
    }
};