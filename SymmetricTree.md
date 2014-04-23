Symmetric Tree
========

##Description
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:
```
    1
   / \
  2   2
 / \ / \
3  4 4  3
```
But the following is not:
```
    1
   / \
  2   2
   \   \
   3    3
```

##Solution

`DFS`

```cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if(!root) return true;
        else return isSymmetricDFS(root->left,root->right);
    }
    bool isSymmetricDFS(TreeNode *t1, TreeNode *t2){
        if(!t1 && !t2) return true;
        if(!t1 || !t2 || t1->val!=t2->val) return false;
        return isSymmetricDFS(t1->left, t2->right) && 
               isSymmetricDFS(t1->right, t2->left);
    }
};
```