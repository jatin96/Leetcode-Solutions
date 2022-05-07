class Solution {
public:
    vector<int> getPreviousSmaller(vector<int> &arr) {
        stack <int> st;
        int n = arr.size();
        vector<int> res(n, -1);
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            
            if (!st.empty())
                res[i] = st.top();
            else
                res[i] = -1;
            
            st.push(i);
        }
        
        return res;
    }
    
    vector<int> getNextSmaller(vector<int> &arr) {
        stack <int> st;
        int n = arr.size();
        vector<int> res(n, -1);
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            
            if (!st.empty())
                res[i] = st.top();
            else
                res[i] = n;
            
            st.push(i);
        }
        
        return res;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        auto prev = getPreviousSmaller(arr);
        auto next = getNextSmaller(arr);
                
        for (int i = 0; i < arr.size(); i++)
            cout << prev[i] << " ";
        cout << "\n";
        
        for (int i = 0; i < arr.size(); i++)
            cout << next[i] << " ";
        cout << "\n";
        long long res = 0;
        for (int i = 0; i < arr.size(); i++) {
            int left = i - prev[i];
            int right = next[i] - i;
            res = (res + arr[i] * left * (long long)right) % 1000000007;
        }
        return (int)res;
}
};