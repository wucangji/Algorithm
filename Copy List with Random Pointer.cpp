
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        for(RandomListNode *cur = head;cur;){
           RandomListNode *node = new RandomListNode(cur->label);
           node->next = cur->next;
           cur->next = node;
           cur = node->next;
        }
        for(RandomListNode *cur = head; cur;){
            if(cur->random!=NULL){
                cur->next->random = cur->random->next;    // random->next = random
            }
            cur = cur->next->next;
        }
        RandomListNode *dummy = new RandomListNode(-1);
        for(RandomListNode *cur = head, *new_cur = dummy;cur;){
            new_cur->next = cur->next;
            new_cur = new_cur->next; // this shold be careful, not cur->next->next
            
            cur->next = cur->next->next;
            cur = cur->next;
        }
        return dummy->next;
    }
};