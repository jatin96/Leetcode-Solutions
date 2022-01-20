class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        map < int, vector<pair<long long, long long>>> valToIdx;
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            if (valToIdx[arr[i]].size() == 0)
                valToIdx[arr[i]].push_back({i, i});
            else {
                int siz = valToIdx[arr[i]].size();
                valToIdx[arr[i]].push_back({i, i + valToIdx[arr[i]][siz - 1].second});
            }
        }
        vector<long long> res(n);
        for (auto it = valToIdx.begin(); it != valToIdx.end(); it++) {
            cout << it -> first << endl;
            vector<pair<long long, long long>> vec = it -> second;
            for (long long i = 0; i < vec.size(); i++) {
                int currIdx = vec[i].first;
                if (i == 0)
                    res[currIdx] = vec[vec.size() - 1].second - vec[i].second - (vec.size() - 1 - i) * vec[i].first;
                else if (i == vec.size() - 1)
                    res[currIdx] = vec[i].first * i - vec[i - 1].second;
                else
                    res[currIdx] = i * vec[i].first - vec[i - 1].second + vec[vec.size() - 1].second - vec[i].second - (vec.size() - 1 - i) * vec[i].first;
            }
        }
        
        return res;
                
    }
};