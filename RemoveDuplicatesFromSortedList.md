Remove Duplicates from Sorted List
======

##Description
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

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
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head || !head->next)
            return head;
        
        ListNode *p = head->next, *q = head;
        while(p){
            if(p->val == q->val){
                ListNode *t = p;
                q->next = p->next;
                p = p->next;
                delete(t);
                continue;
            }
            q = p;
            p = p->next;
        }
        return head;
    }
};
```
