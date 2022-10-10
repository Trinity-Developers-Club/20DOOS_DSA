// Ques: https://leetcode.com/problems/add-two-numbers/submissions/

class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy=new ListNode();
        ListNode temp=dummy;
        int sum=0;
        int carry=0;
        while(l1!=null||l2!=null||carry!=0){
            sum=0;
            if(l1!=null&&l2!=null){
                sum+=(l1.val+l2.val);
                l1=l1.next;
                l2=l2.next;
            }
            else if(l1!=null){
                sum+=l1.val;
                 l1=l1.next;
            }
             else if(l2!=null){
                sum+=l2.val;
                  l2=l2.next;
            }
            sum+=carry;
            ListNode node=new ListNode(sum%10);
            temp.next=node;
            temp=temp.next;
            carry=sum/10;
        }
        return dummy.next;
    }
}
