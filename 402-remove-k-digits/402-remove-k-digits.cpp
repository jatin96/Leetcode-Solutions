class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        
        st.push(num[0]);
        
        for (int i = 1; i < num.length(); i++) {
            while (!st.empty() && st.top() > num[i] && k) {
                k--;
                st.pop();
            }
            if (st.empty() && num[i] == '0')
                continue;
            
            st.push(num[i]);
        }
        
        while(!st.empty() && k)
        {
            st.pop();
            k--;
        }
        
        string res = "";
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        return res == "" ? "0" : res;
    }
};