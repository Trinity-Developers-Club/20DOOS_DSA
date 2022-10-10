// Ques: https://leetcode.com/problems/rotate-list/

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
    public ListNode rotateRight(ListNode head, int k) {
      int length=0;
        ListNode ptr=head;
        while(ptr!=null){
            ptr=ptr.next;
            ++length;
        }
        if(length!=0)
        k%=length;
        if(head==null)
            return head;
    if(k==0)
        return head;
        ListNode dummy=new ListNode();
        dummy.next=head;
        int n=1;
        ListNode fast=dummy;
        ListNode slow=dummy;
        while(n<=k){
            fast=fast.next;
            ++n;
        }
        while(fast.next!=null){
            fast=fast.next;
            slow=slow.next;
        }
      
      
              fast.next=head;
            head=slow.next;

        slow.next=null;
        return head;
    }
}
