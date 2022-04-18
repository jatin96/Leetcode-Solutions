/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Compare
{
public:
    bool operator() (ListNode *a, ListNode* b)
    {
        return a -> val < b -> val;
    }
};

class Solution {
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>>> pq;
        
        int cnt = 0;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] == NULL)
                cnt++;
            else {
                pq.push({lists[i] -> val, lists[i]});
            }
        }
        
        if (cnt == lists.size())
            return NULL;
        
        bool flag = false;
        
        ListNode *iterNode, * retNode;
        while (!pq.empty()) {
            ListNode *currNode = pq.top().second;
            cout << currNode -> val << endl;
            pq.pop();
            
            if (!flag) {
                flag = true;
                iterNode = currNode;
                retNode = currNode;
            } else {
                iterNode -> next = currNode;
                iterNode = currNode;
            }
            
            if (currNode -> next != NULL)
                pq.push({currNode -> next -> val, currNode -> next});
        }
        
        return retNode;
    }
};