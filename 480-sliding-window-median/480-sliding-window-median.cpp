class Solution {
public:
    set<pair<double, int>> minHeap;
    set<pair<double, int>, greater<>> maxHeap;
    vector<double> ans;
    int k, n;
    void balance() {
        auto it = minHeap.begin();
        maxHeap.insert(*it);
        minHeap.erase(minHeap.begin());
        
        if (maxHeap.size() > minHeap.size()) {
            auto it = maxHeap.begin();
            minHeap.insert(*it);
            maxHeap.erase(maxHeap.begin());
        }
    }
    
    double getMedian() {
        if (k % 2 == 0)
            return (maxHeap.begin() -> first + minHeap.begin() -> first) / 2.0;
        else
            return (minHeap.begin() -> first * 1.0);
    }
    
     void adjust(){
        if(maxHeap.size() > minHeap.size()){
            auto it = *maxHeap.begin();
            minHeap.insert(it);
            maxHeap.erase(maxHeap.begin());
        }
        // size of minHeap was 1 more than maxHeap and element deleted from maxHeap
        if(minHeap.size() > 1 + maxHeap.size()){
            auto it = *minHeap.begin();
            minHeap.erase(minHeap.begin());
            maxHeap.insert(it);
        }
    }
    
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        this -> k = k;
        this -> n = nums.size();
        for (int i = 0; i < k; i++) {
            minHeap.insert({nums[i], i});
            balance();
        }
        
        ans.push_back(getMedian());
        
        for (int i = k; i < n; i ++) {
            
            if (minHeap.find({nums[i - k], i - k}) != minHeap.end()) {
                minHeap.erase({nums[i - k], i - k});
            } else {
                maxHeap.erase({nums[i - k], i - k});
            }
            
            minHeap.insert({nums[i], i});
            
            balance();
            
            ans.push_back(getMedian());
        }
        
        return ans;
    }
};