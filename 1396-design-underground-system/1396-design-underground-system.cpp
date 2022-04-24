class UndergroundSystem {
public:
    map<int, pair<string, int>> checkInMap;
    map<pair<string, string>, vector<int>> averageTimeMap;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInMap[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationB, int t) {
        int checkInTime = checkInMap[id].second;
        string stationA = checkInMap[id].first;
        int totalTime = t - checkInTime;
        averageTimeMap[{stationA, stationB}].push_back(totalTime);
    }
    
    double getAverageTime(string startStation, string endStation) {
        vector<int> arr = averageTimeMap[{startStation, endStation}];
        return (accumulate(arr.begin(), arr.end(), 0) * 1.0) / arr.size();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */