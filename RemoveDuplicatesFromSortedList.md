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
        if(head==NULL||head->next==NULL)
            return head;
        ListNode *p = head,*q = head->next;
        int count = 0;
        for(;q!=NULL;q = q->next){
            if(q->val != p->val){
                if(count!=0){
                    int i = 0;
                    for(ListNode *s = p->next;i<count;i++,s=s->next){
                        delete(s);
                    }
                    count = 0;
                    p->next = q;
                }
                p = q;
            } else {
                ++count;
            }
        }
        if(count>0){
            int i = 0;
            for(ListNode *s = p->next;i<count;i++,s=s->next){
                delete(s);
            }
            p->next = q;
        }
        return head;
    }
};
```
