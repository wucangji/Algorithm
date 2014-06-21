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
    ListNode *sortList(ListNode *head) {
        if(!head || !head->next) return head;    // cannot miss the special case
        ListNode *fast, *slow;
        fast = head;
        slow = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *p2 = slow;
        slow=slow->next;
        p2->next = NULL;         //  This is the easy wrong part
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(slow);
        return merge2list(l1, l2);
    }
private:
    ListNode *merge2list(ListNode *l1, ListNode *l2){
        ListNode dummy(-1);
        ListNode *p=&dummy;
        while(l1 || l2){
            int l1val = l1==NULL? INT_MAX:l1->val;
            int l2val = l2==NULL? INT_MAX:l2->val;
            if(l1val<l2val){
                p->next = l1;
                l1=l1->next;
            }
            else{
                p->next = l2;
                l2=l2->next;
            }
            p=p->next;    // need to move p  !!!
        }
        return dummy.next;
    }
};