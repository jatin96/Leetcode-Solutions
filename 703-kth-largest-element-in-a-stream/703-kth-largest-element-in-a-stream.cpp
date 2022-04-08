class KthLargest {
public:
    vector<int> nums;
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    KthLargest(int k, vector<int>& nums) {
        this -> nums = nums;
        this -> k = k;
        process();
    }
    
    void balance(int x) {
        if (pq.size() < k) {
             pq.push(x);
        }
        else if (pq.top() <= x) {
            pq.pop();
            pq.push(x);
        }
    }
    
    void process() {
        for (int i = 0; i < nums.size(); i++) {
           balance(nums[i]);
        }
    }
    int add(int val) {
        balance(val);
        cout << pq.top() << endl;
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */