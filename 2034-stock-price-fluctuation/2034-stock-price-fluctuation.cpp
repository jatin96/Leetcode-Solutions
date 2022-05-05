class StockPrice {
public:
    map<int, int> tracker;
    set <pair<int, int>> priceSet;
    StockPrice() {
        tracker.clear();
    }
    
    void update(int timestamp, int price) {
        priceSet.erase({tracker[timestamp], timestamp});
        tracker[timestamp] = price;
        priceSet.insert({price, timestamp});
    }
    
    int current() {
        return tracker.rbegin() -> second;
    }
    
    int maximum() {
        return (*priceSet.rbegin()).first;
    }
    
    int minimum() {
        return (*priceSet.begin()).first;        
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */