Binary Tree Level Order Traversal II
======
##Description
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree `{3,9,20,#,#,15,7}`,
```
    3
   / \
  9  20
    /  \
   15   7
```
return its bottom-up level order traversal as:
```
[
  [15,7]
  [9,20],
  [3],
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
    void levelOrderBottomRe(unordered_map<int, vector<int>> &res, TreeNode *root, int height){
        if(!root) return;
        levelOrderBottomRe(res,root->left,height+1);
        levelOrderBottomRe(res,root->right,height+1);
        res[height].push_back(root->val);
    }
    
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> res;
        unordered_map<int,vector<int>> levelRes;
        levelOrderBottomRe(levelRes,root,0);
        for(int i=levelRes.size()-1;i>=0;--i)
            res.push_back(levelRes[i]);
        return res;
    }
};
```