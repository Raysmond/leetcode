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
        return dfs(root->left, root->right);
    }
    
    bool dfs(TreeNode *n1, TreeNode *n2){
        if(!n1&&!n2) return true;
        if(!n1||!n2 ||n1->val != n2->val) return false;
        return dfs(n1->left, n2->right) && dfs(n1->right, n2->left);
    }
};
```