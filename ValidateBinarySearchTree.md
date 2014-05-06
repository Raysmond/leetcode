Validate Binary Search Tree
======

##Description
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

##Solution
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
    bool isValidBST(TreeNode *root) {
        return isValidBSTRe(root,INT_MIN,INT_MAX);
    }
    
    bool isValidBSTRe(TreeNode *node, int min, int max){
        if(!node) return true;
        if(node->val <= min || node->val >= max) return false;
        return isValidBSTRe(node->left, min, node->val) && 
               isValidBSTRe(node->right, node->val, max);
    }
};
```