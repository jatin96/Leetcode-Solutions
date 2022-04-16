class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int, char>> Q;
        int cycle = n + 1;
        int freq_cnt[26] = {};
        
        for (int i = 0; i < tasks.size(); i++)
            freq_cnt[tasks[i] - 'A']++;
        
        for (int i = 0; i < 26; i++) {
            if (freq_cnt[i] != 0)
                Q.push({freq_cnt[i], (char)(i + 'A')});
        }
        
        int total_time = 0;
        while (!Q.empty()) {
            
            vector<pair<int, char>> tmp;
            int time = 0;
            for (int i = 0; i < cycle && !Q.empty(); i++) {
                tmp.push_back(Q.top());
                Q.pop();
            }
            
            for (int i = 0; i < tmp.size(); i++) {
                tmp[i].first--;
                time++;
                if (tmp[i].first != 0)
                    Q.push({tmp[i].first, tmp[i].second});
            }
            
            total_time += !Q.empty() ? cycle : time;
        }
        
        return total_time;
    }
};