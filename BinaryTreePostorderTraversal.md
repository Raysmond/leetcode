Binary Tree Postorder Traversal 
======

##Description
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree `{1,#,2,3}`,
```
   1
    \
     2
    /
   3
```
return `[3,2,1]`.

Note: Recursive solution is trivial, could you do it iteratively?

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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ret;
        stack<TreeNode*> s;
        TreeNode *cur = root, *last = NULL;
        while(cur || !s.empty()){
            if(cur){
                s.push(cur);
                cur = cur->left;
            } else{
                TreeNode *top = s.top();
                if(top->right&&last!=top->right){
                    cur = top->right;
                } else{
                    ret.push_back(top->val);
                    last = top;
                    s.pop();
                }
            }
        }
        return ret;
    }
};
```