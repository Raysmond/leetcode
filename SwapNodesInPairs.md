Swap Nodes in Pairs
========

##Description
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given `1->2->3->4`, you should return the list as `2->1->4->3`.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

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
    ListNode *swapPairs(ListNode *head) {
        if(head==NULL) return NULL;
        ListNode *p = head, *q = head->next,*r=NULL;
        if(q!=NULL) head = q;
        while(p!=NULL&&q!=NULL){
            p->next = q->next;
            q->next = p;
            if(r!=NULL) r->next = q;
            r = p;
            p = p->next;
            if(p!=NULL) q = p->next;
            else q = NULL;
        }
        return head;
    }
};
```