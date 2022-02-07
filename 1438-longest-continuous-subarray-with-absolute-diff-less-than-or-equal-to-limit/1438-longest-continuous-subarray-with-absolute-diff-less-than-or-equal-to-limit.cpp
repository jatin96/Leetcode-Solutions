class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
                
        // array length
        int n = nums.size();
        
        // max and min deque
        deque<int>maxD;
        deque<int>minD;
        
        // first pointer of the window
        int first = 0;
        
        // longest sub-array length
        int maxL = 0;
        
        // lopp through the array
        for(int last = 0; last < n; last++)
        {
            // remove elements from maxD which are less than nums[last]
            // As maxD is Non-increasing list we compare and remove from the back of maxD
            // maxD will contain the max elements from first to last of the window in a non-increasing order
            while(!maxD.empty() && nums[last]>maxD.back())maxD.pop_back();
            
            // remove elements from minD which are greater than nums[last]
            // As minD is Non-decreasing list we compare and remove from the back of minD
            // minD will contain the min elements from first to last of the window in a non-decreasing order
            while(!minD.empty() && nums[last]<minD.back())minD.pop_back();
            
            // push back nums[last] in maxD and minD as all elements in maxD
            // are greater than nums[last] and all elements in minD are less than nums[last]
            maxD.push_back(nums[last]);
            minD.push_back(nums[last]);
            
            // mismatch condition as max and min element diff is greater than limit 
            // thus window is not valid and so need to shrink window by increasing first pointer
            if((maxD.front()-minD.front())>limit)
            {
                // before increasing first pointer need to remove the first pointer element
                // from maxD or minD if it is the current max or min element in the window
                // which means nums[first] == maxD.front() or nums[first] == minD.front()
                // If nums[first] is not the current max or min element then it will get removed 
                // at the begining of future loop when nums[future_last] > nums[current_first] from maxD
                // and when nums[future_last] < nums[current_first] from minD 
                if(maxD.front()==nums[first])maxD.pop_front();
                if(minD.front()==nums[first])minD.pop_front();
                first++;
            }
            
            // calculate the max valid subarray length and get the max length
            maxL = max(maxL,last-first+1);            
        }
        
        return maxL;
    }
};