class DetectSquares {
public:
    vector<pair<int, int>> points;
    int cnt[1007][1007] = {};
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        points.push_back({point[0], point[1]});
        cnt[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        
        int res = 0;
        for (auto point1 : points) {
            int x = point[0];
            int y = point[1];
            int x1 = point1.first;
            int y1 = point1.second;
            
            if (abs(x1 - x) != abs(y1 - y) || abs(x - x1) == 0 || abs (y - y1) == 0)
                continue;
            
            res += cnt[x][y1] * cnt[x1][y];
        }
        
        return res;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */