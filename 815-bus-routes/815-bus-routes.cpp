class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        queue< pair<int, int>> Q;
        unordered_set<int> routeSet[100007];
        
        for (int i = 0; i < routes.size(); i++) {
            for (int j = 0; j < routes[i].size(); j++)
                routeSet[routes[i][j]].insert(i);
        }
        
        
        bool visRoutes[100007] = {false};
        
        Q.push({source, 0});
        
        while (!Q.empty()) {
            int currStop = Q.front().first;
            int currBuses = Q.front().second;
            
            if (currStop == target)
                return currBuses;
            
            Q.pop();
            
            auto connectedRoutes = routeSet[currStop];
            
            for (int route : connectedRoutes) {
                if (visRoutes[route] == true)
                    continue;
                
                for (int i = 0; i < routes[route].size(); i++) {
                    int nextStop = routes[route][i];
                    if (nextStop == currStop)
                        continue;
                    
                    Q.push({nextStop, currBuses + 1});
                }
                visRoutes[route] = true;
            }
        }
        
        return -1;
    }
};