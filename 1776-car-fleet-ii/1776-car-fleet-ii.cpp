class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        stack<int> st;
        int n = cars.size();
        vector<double> res(n, -1);
        
        for (int i = n - 1; i >= 0; i--) {
            int pos = cars[i][0];
            int speed = cars[i][1];
            
            while (!st.empty()) {
                int pos1 = cars[st.top()][0];
                int speed1 = cars[st.top()][1];
                
                double collisionTime = (1.0 * abs(pos - pos1)) / abs(speed - speed1);
                
                if (speed1 >= speed || (collisionTime >= res[st.top()] && res[st.top()] > 0))
                    st.pop();
                else
                    break;
            }
            
            if (!st.empty())
                res[i] = ((1.0 * abs(cars[st.top()][0] - pos)) / (abs(cars[st.top()][1] - speed)));
            
            st.push(i);
        }
        
        return res;
    }
};