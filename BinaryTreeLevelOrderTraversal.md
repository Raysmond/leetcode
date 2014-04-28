Binary Tree Level Order Traversal 
======
##Description
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree `{3,9,20,#,#,15,7}`,
```
    3
   / \
  9  20
    /  \
   15   7
```
return its level order traversal as:
```
[
  [3],
  [9,20],
  [15,7]
]
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        levelOrderDFS(res, root, 0);
        return res;
    }
    
    void levelOrderDFS(vector<vector<int>> &res, TreeNode *root, int level){
        if(!root) return;
        if(res.size()<=level) res.push_back(vector<int>());
        res[level].push_back(root->val);
        levelOrderDFS(res,root->left,level+1);
        levelOrderDFS(res,root->right,level+1);
    }
};
```