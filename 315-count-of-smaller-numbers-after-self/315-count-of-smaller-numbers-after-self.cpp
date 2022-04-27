class Solution {
public:
    int N;
    vector<pair<int, int>> arr;
    vector<int> count;
    void merge(int low, int mid, int high) {
        int i = low, n = mid, j = mid + 1, m = high;
        int cnt = 0;
        vector<pair<int, int>> tmp;
        while (i <= n && j <= m) {
            if (arr[i].first > arr[j].first) {
                cnt++;
                tmp.push_back({arr[j].first, arr[j].second});
                j++;
            } else {
                count[arr[i].second] += cnt;
                tmp.push_back({arr[i].first, arr[i].second});
                i++;
            }
        }
        
        while (i <= n) {
            count[arr[i].second] += cnt;
            tmp.push_back({arr[i].first, arr[i].second});
            i++;
        }
        
        while (j <= m) {
            tmp.push_back({arr[j].first, arr[j].second});
            j++;
        }
        
        int x = 0;
        for (int i = low; i<= high; i++)
            arr[i] = tmp[x++];
    }
    
    void mergeSort(int low, int high) {
        if (low < high) {
            int mid = (low + high) / 2;
            mergeSort(low , mid);
            mergeSort(mid + 1, high);
            merge(low, mid, high);
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        
        N = nums.size();
        count.resize(N, 0);
        for (int i = 0; i < N; i++) {
            arr.push_back({nums[i], i});
        }
        
        mergeSort(0, N - 1);
        
        return count;
    }
};