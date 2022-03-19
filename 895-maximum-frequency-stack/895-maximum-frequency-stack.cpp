class FreqStack {
public:
    map<int, vector<int>> freqToElements;
    map<int, int> elementToFreq;
    int maxFreq = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        elementToFreq[val]++;
        int currFreq = elementToFreq[val];
        freqToElements[currFreq].push_back(val);
        maxFreq = max(maxFreq, currFreq);
    }
    
    int pop() {
        int res = freqToElements[maxFreq].back();
        freqToElements[maxFreq].pop_back();
        elementToFreq[res]--;
        
        if (freqToElements[maxFreq].size() == 0)
            maxFreq--;
        
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */