class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> dq;
        
        int curr = 0;
        for (int i = nums.size() - 1; i>= 0; i--) {
            curr = nums[i] + (dq.empty() ? 0 : nums[dq.front()]);
            
            while(!dq.empty() && curr > nums[dq.back()])
                dq.pop_back();
            
            dq.push_back(i);
            
            while(!dq.empty() && dq.front() >= i + k)
                dq.pop_front();
            
            nums[i] = curr;
        }
        
        return curr;
    }
};