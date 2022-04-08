class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        
        for (int i = 0; i < stones.size(); i ++) {
            pq.push(stones[i]);
        }
        
        while (pq.size() > 1) {
            int big = pq.top();
            pq.pop();
            int small = pq.top();
            pq.pop();
            
            if (big != small) {
                pq.push(big - small);
            }
        }
        
        return pq.size() == 0 ? 0 : pq.top();
    }
};