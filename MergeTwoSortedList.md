Merge Two Sorted Lists
=====
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

## Solution

```
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode *list = NULL, *head = NULL;
        while(l1 || l2){
            if(!l1) { list->next = l2; break; }
            if(!l2) { list->next = l1; break; }
            
            ListNode *t = l1;
            if(l1->val>l2->val){
                t = l2;
                l2 = l2->next;
            } else{
                l1 = l1->next;
            }
            
            if(head == NULL)
                head = list = t;
            else{
                list->next = t;
                list = list->next;
            }
        }
        return head;
    }
    
};
```