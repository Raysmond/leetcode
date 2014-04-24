Add Two Numbers 
======

##Description
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

```
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
```

##Solution
`Two pointers`
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = NULL, *tail = NULL;
        int carry = 0;
        ListNode *p1 = l1,*p2 = l2;
        for(;p1&&p2;p1 = p1->next,p2=p2->next){
            ListNode *node = new ListNode((p1->val+p2->val+carry)%10);
            carry = (p1->val+p2->val+carry)/10;
            if(!head) head = tail = node;
            else{
                tail->next = node;
                tail = tail->next;
            }
        }
        
        for(ListNode *p = p1 ? p1 : p2;p;p=p->next){
            tail->next = new ListNode((p->val+carry)%10);
            tail = tail->next;
            carry = (p->val+carry)/10;
        }
        if(carry>0)
            tail->next = new ListNode(carry);
        return head;
    }
};
```