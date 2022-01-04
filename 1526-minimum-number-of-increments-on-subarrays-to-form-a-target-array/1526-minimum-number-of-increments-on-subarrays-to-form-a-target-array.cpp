class Solution {
public:
    vector<int>seg_tree;
    vector<int>target;
    int n;
    void build(int idx, int low, int high) {
        if (low == high) {
            seg_tree[idx] = low;
            return;
        }
        int mid = (low + high) >> 1;
        build(2*idx + 1, low , mid);
        build(2*idx + 2, mid + 1, high);
        seg_tree[idx] = target[seg_tree[2 * idx + 1]] < target[seg_tree[2 * idx + 2]] ?
            seg_tree[2 * idx + 1] : seg_tree[2 * idx + 2];
    }
    
    int query(int idx, int low, int high, int ql, int qr) {
        if(low > qr || high < ql)
            return -1;
        if(low >= ql && high <= qr)
            return seg_tree[idx];
        int mid = (low + high) >> 1;
        
        int left_min = query(2*idx + 1, low, mid, ql, qr);
        int right_min = query(2*idx + 2, mid + 1, high, ql, qr);
        
        if(left_min == -1)
            return right_min;
        if(right_min == -1)
            return left_min;
        
        return target[left_min] < target[right_min] ? left_min : right_min;
        
    }
    
    int solve_it(int low, int high, int carry_over) {
        if(low <= high) {
            int min_idx = query(0, 0, n - 1, low, high);
            int val = target[min_idx] - carry_over;
            
            return val + solve_it(low, min_idx - 1, target[min_idx]) + solve_it(min_idx + 1, high, target[min_idx]);
        }
        
        return 0;
    }
    
    
    int minNumberOperations(vector<int>& target) {
        n = target.size();
        seg_tree.resize(4*n + 1);
        this -> target = target;    
        build(0, 0 , n - 1);
                
        return solve_it(0, n - 1, 0);
    }
};