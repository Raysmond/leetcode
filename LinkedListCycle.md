Linked List Cycle 
======
##Description
Given a linked list, determine if it has a cycle in it.

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
    bool hasCycle(ListNode *head) {
        if(head==NULL)
            return false;
        ListNode *p = head, *q=head;
        for(;;){
            p = p->next;
            q = q->next;
            if(q==NULL||q->next==NULL)
                return false;
            q = q->next;
            if(q==p)
                return true;
        }
    }
};

```