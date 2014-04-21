Remove Duplicates from Sorted List II
=======

##Description
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
##Solution
代码写得比较乱，不够优雅，待优化...
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
        ListNode *h = head, *lasth=head, *last = head, *p = head;
        bool dup = false;
        if(p!=NULL)
        for(p = p->next;p!=NULL;){
            if(p->val != last->val){
                if(dup){
                    ListNode *d = last;
                    if(d==head){
                        h = head = p;
                    } else{
                        h = p;
                        lasth->next = h;
                    }
                    delete(d);
                    dup = false;
                } else{
                    h->next = p;
                    lasth = h;
                    h = h->next;
                }
                last = p;
                p = p->next;
            } else{
                dup = true;
                ListNode *d = p;
                p = p->next;
                delete(d);
            }
        }
        if(h) h->next = NULL;
        if(dup){
            if(h==head) head = NULL;
            else lasth->next = NULL;
            delete(h);
        }
        return head;
    }

};
```
