class MyCalendarThree {
public:
    map<int, int> timeline;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        timeline[start]++;
        timeline[end]--;
        
        int currEvents = 0, res = 0;
        for (auto entry: timeline) {
            currEvents += entry.second;
            res = max(res, currEvents);
        }
        
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */