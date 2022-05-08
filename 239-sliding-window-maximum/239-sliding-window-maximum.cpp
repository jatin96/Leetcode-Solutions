class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int numsSize = nums.size();
        deque<int> window;
        vector<int> maxWindowResult;
        
        for (int i = 0; i < numsSize; i++) {
            if (!window.empty() && window.front() == i - k) window.pop_front();
            while (!window.empty() && nums[window.back()] < nums[i]) window.pop_back();
            
            window.push_back(i);
            
            if(i >= k - 1)
                maxWindowResult.push_back(nums[window.front()]);
        }
        
        return maxWindowResult;
        
    }
};