class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums2.size();
        
        unordered_map<int ,int > nextGreater;
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i])
                st.pop();
            
            if (!st.empty())
                nextGreater[nums2[i]] = st.top();
            else
                nextGreater[nums2[i]] = -1;
            
            st.push(nums2[i]);
        }
        
        vector<int> res;
        for (int i = 0; i < nums1.size(); i++) {
            int x = nums1[i];
            res.push_back(nextGreater[x]);
        }
        
        return res;
        
    }
};