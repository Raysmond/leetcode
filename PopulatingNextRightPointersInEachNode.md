Populating Next Right Pointers in Each Node
======

##Description

Given a binary tree

```cpp
    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
```
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
```
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
```
After calling your function, the tree should look like:
```
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
```

##Solution
```cpp
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeLinkNode*> v;
    
    void connect(TreeLinkNode *root) {
        if(root == NULL || root->left == NULL)
            return;
        TreeLinkNode *p = root;
        queue<TreeLinkNode*> q;
        q.push(p);
        while(!q.empty()){
            TreeLinkNode* cur = q.front();
            v.push_back(cur);
            q.pop();
            if(cur->left!=NULL){
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        
        int height = (int)(log(v.size())/log(2)) + 1;
        for(int i=1;i<height;i++){
            int j = (int) pow(2, i) - 1;
            for(int k = 0; k < j; k++)
                v[k+j]->next = v[k+j+1];
        }
    }
};
```
