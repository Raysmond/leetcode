Binary Tree Preorder Traversal
=======

##Description
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree `{1,#,2,3}`,
```
   1
    \
     2
    /
   3
```
return `[1,2,3]`.

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
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode*> s;
        vector<int> ret;
        TreeNode *cur = root;
        while(cur || !s.empty()){
            if(cur){
                ret.push_back(cur->val);
                s.push(cur);
                cur = cur->left;
            } else{
                cur = s.top()->right;
                s.pop();
            }
        }
        return ret;
    }
};
```