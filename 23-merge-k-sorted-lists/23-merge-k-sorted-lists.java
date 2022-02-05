/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode> pq = new PriorityQueue<>(new CustomComparator());
        int cnt = 0;
        for (int i = 0; i < lists.length; i++) {
            if(lists[i] == null) {
                cnt++;
            }
            else {
                 pq.add(lists[i]);
            }
        }
        
        if (cnt == lists.length)
            return null;
        
        ListNode res = pq.poll();
        if(res.next != null)
            pq.add(res.next);
        
        ListNode tmp = res;
        while (!pq.isEmpty()) {
            ListNode node = pq.poll();
            tmp.next = node;
            if (node.next != null)
                pq.add(node.next);
            
            tmp = tmp.next;
        }
        
        
        return res;
        
        
    }
    
    class CustomComparator implements Comparator<ListNode> {
        public int compare(ListNode a, ListNode b) {
            return a.val - b.val;
        }
    }
}