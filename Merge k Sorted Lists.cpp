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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // do not forget to check the corner case
        if(lists.empty()) return NULL;
        int n = lists.size();
        while(n>1){   // while is important 
            int k = (n+1)/2;
            for(int i=0; i<n/2 ;i++){
                lists[i] = merge2lists(lists[i],lists[i+k]);
            }
            n = k;
        }

        return lists[0];   // this is nklog k   
       //http://www.cnblogs.com/TenosDoIt/p/3673188.html
    }
private:    
    ListNode *merge2lists(ListNode *l1, ListNode *l2){
        ListNode dummy(-1);
        ListNode *p = &dummy;
        while(l1 || l2){
            int val1 = l1 == NULL? INT_MAX:l1->val;   // Good way to prevent NULL
            int val2 = l2 == NULL? INT_MAX:l2->val;
            if(val1<val2){
                p->next = l1;
                l1 = l1->next;
            }
            else{
                p->next = l2;
                l2 = l2->next;
            }
            p=p->next;
        }
        return dummy.next;
    }
};