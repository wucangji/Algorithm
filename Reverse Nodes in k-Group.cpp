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
    // iterate version
    ListNode *reverseKGroup(ListNode *head, int k) {
        // special case
        if(!head || !head->next || k<2) return head;
        
        ListNode *dummy = new ListNode(-1);
        ListNode *prev = dummy;
        dummy->next = head;
        int i = 0;
        while(head){
            i++;
            if(i%k == 0){
                prev = reverse(prev,head->next);
                head = prev->next;     // should not forget this step
            }
            else{
                head=head->next;
            }
        }
        return dummy->next;
    }
private:
    ListNode *reverse(ListNode *head2, ListNode *next){
        ListNode *prev = head2->next;
        ListNode *cur = prev->next;
        while(cur != next){
            prev->next = cur->next;
            cur->next = head2->next;
            head2->next = cur;
            cur = prev->next;
        }
        return prev;   // should return prev, not cur, cur == next now
    }
};
