class StockSpanner {
public:
    
    vector<int> prices;
    stack<int> st;
    StockSpanner() {
        prices.push_back(INT_MAX);
        st.push(0);
    }
    
    int next(int currPrice) {
        int res = 1;
        prices.push_back(currPrice);
        while (!st.empty() && prices[st.top()] <= currPrice)
            st.pop();
        
        if (!st.empty())
            res = (prices.size() - st.top() - 1);
        else 
            res = 1;
        
        st.push(prices.size() - 1);
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */