// Ques:https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
    public ListNode deleteDuplicates(ListNode head) {
        if(head==null)
            return null;
        if(head.next==null)
            return head;
        ListNode ptr1=head;
        ListNode record=null;
        ListNode temp =null;
        int flag=0;
        while(ptr1!=null&&ptr1.next!=null){
            flag=0;
 while(ptr1.next!=null&&ptr1.next.val==ptr1.val){
ptr1=ptr1.next;
                        flag=1;
        }
        if(flag==1){
            // record.next=ptr1.next;
             if(ptr1.val==head.val){
                head=ptr1.next;
            }
            temp=ptr1.next;
            ptr1.next=null;
           
            ptr1=temp;
            if(record!=null)
            record.next=temp;
        }
        else{
             record=ptr1;
           ptr1=ptr1.next;
             
        }
      
        }
return head;
        
    }
}
