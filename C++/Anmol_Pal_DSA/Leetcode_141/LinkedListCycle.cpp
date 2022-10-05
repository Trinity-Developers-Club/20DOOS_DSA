/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(struct ListNode *head) {
    struct ListNode *p,*q;
    p=head;
    q=p;
    if(p==NULL){
        return 0;
    }
    while(p->next!=NULL){
        p=p->next;
        if(q->next==NULL){
            return 0;
        }
        q=q->next;
        if(q->next==NULL){
            return 0;
        }
        q=q->next;
        if(p==q){
            return 1;
        }
    }
    return 0;
    
}
};
