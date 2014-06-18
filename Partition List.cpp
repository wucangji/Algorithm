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
    ListNode *partition(ListNode *head, int x) {
        ListNode *left = new ListNode(-1);
        ListNode *right = new ListNode(-1);
        ListNode *leftcur = left;
        ListNode *rightcur = right;
        ListNode *cur = head;
        while(cur){
            if(cur->val < x){
                leftcur->next = cur;
                leftcur = leftcur->next;
            }
            else{
                rightcur->next = cur;
                rightcur = rightcur->next;
            }
            cur = cur->next; // do not forget moving the cur~!
        }
        rightcur->next = NULL;
        leftcur->next=right->next;
        return left->next;
    }
};