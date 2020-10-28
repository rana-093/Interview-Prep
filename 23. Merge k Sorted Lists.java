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
    	ListNode ans = new ListNode(0);
    	ListNode head = ans;
    	PriorityQueue< Integer > pq = new PriorityQueue< Integer >();
    	for(int i = 0; i < lists.length; i++) {
    		ListNode res = lists[i];
    		while(res!= null) {
    			pq.add(res.val);
    			res = res.next;
    		}
    	}
    	while(!pq.isEmpty()) {
    		int val = pq.poll();
    		ListNode cur = new ListNode(val);
    		ans.next = cur;
    		ans = ans.next;
    	}
    	return head.next;
    	
    }
}
