Reorder List
======

##Description
Given a singly linked list `L: L0→L1→…→Ln-1→Ln`,
reorder it to: `L0→Ln→L1→Ln-1→L2→Ln-2→…`

You must do this in-place without altering the nodes' values.

For example,
Given `{1,2,3,4}`, reorder it to `{1,4,2,3}`.

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
    void reorderList(ListNode *head) {
        if(head==NULL || head->next == NULL || head->next->next == NULL)
            return;
        ListNode *p = head, *q = head;
        vector<ListNode*> list;
        for (p = head; p!=NULL; p=p->next) {
            list.push_back(p);
        }
        int i = 0;
        int n = list.size();
        for (;;) {
            ListNode *t =list[n - i - 1];
            t->next = q->next;
            q->next = t;
            q = t;
            q = q->next;
            if((i++)>=n/2){
                q->next = NULL;
                break;
            }
        }
    }
};
```