Binary Tree Inorder Traversal
=======

##Description
iven a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree `{1,#,2,3}`,
```
   1
    \
     2
    /
   3
```
return `[1,3,2]`.

Note: Recursive solution is trivial, could you do it iteratively?

confused what `"{1,#,2,3}"` means? > read more on how binary tree is serialized on OJ.

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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ret;
        stack<TreeNode*> s;
        TreeNode *cur = root;
        while(cur || !s.empty()){
            if(cur){
                s.push(cur);
                cur = cur->left;
            } else if(!s.empty()){
                ret.push_back(s.top()->val);
                cur = s.top()->right;
                s.pop();
            }
        }
        return ret;
    }
};
```