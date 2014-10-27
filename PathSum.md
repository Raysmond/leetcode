Path Sum
====
Source: https://oj.leetcode.com/problems/path-sum/

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
```
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
```
return true, as there exist a root-to-leaf path `5->4->11->2` which sum is 22.

## Solution
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
    bool hasPathSum(TreeNode *root, int sum) {
        if(root==NULL) return false;
        return dfs(root, 0, sum);
    }
    
    bool dfs(TreeNode *root, int curSum, int sum){
        if(root==NULL) return false;
        curSum+=root->val;
        if(root->left == NULL && root->right == NULL && curSum == sum) return true;
        return dfs(root->left, curSum, sum) || dfs(root->right, curSum, sum);
    }
};
```