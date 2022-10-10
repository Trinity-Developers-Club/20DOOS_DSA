// Ques: https://leetcode.com/problems/palindrome-linked-list/submissions/

class Solution {
    public boolean isPalindrome(ListNode head) {
        ListNode mid=middleNode(head);
        mid.next=reverse(mid.next);
        mid=mid.next;
        ListNode dummy=head;
        while(mid!=null){
            if(mid.val==dummy.val){
                mid=mid.next;
                dummy=dummy.next;
            }
                else
                    return false;
        }
        return true;
    }
    public static ListNode middleNode(ListNode head){
       ListNode slow=head;
        ListNode fast=head;
        while(fast.next!=null&&fast.next.next!=null){
            fast=fast.next.next;
            slow=slow.next;
        }
      return slow;
    }
    public static ListNode reverse(ListNode head){
        ListNode pre=null;
        ListNode next=null;
        while(head!=null){
            next=head.next;
            head.next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
}
