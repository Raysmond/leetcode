Linked List Cycle II
======

##Description
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?

##Solution
```cpp
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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)
            return NULL;
        ListNode *p = head, *q=head;
        for(;;){
            p = p->next;
            q = q->next;
            if(q==NULL||q->next==NULL)
                return NULL;
            q = q->next;
            if(q == p){
                p = head;
                for(;p!=q;q = q->next,p = p->next);
                return p;
            }
        }
    }
};
```