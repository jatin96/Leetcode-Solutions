class Solution {
public:
    bool predicate(int expectedH, vector<int>& citations, int n) {
        
        int more = 0, less = 0, same = 0;
        for (int citation : citations) {
            if (citation == expectedH) same++;
            else if (citation > expectedH) more++;
            else less++;
        }
        
        if (more == expectedH) return true;
        
        if (more + same >= expectedH) return true;
        
        return false;
    }
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        
        int low = 0, high = n, res = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (predicate(mid, citations, n)) {
                low = mid + 1;
                res = mid;
            } else
                high = mid - 1;
        }
        
        return res;
    }
};