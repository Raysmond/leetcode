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
**方法一：DFS**
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

    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> res;
        dfs(root,1,res);
        reverse(res.begin(),res.end());
        return res;
    }
    
    void dfs(TreeNode *root, int level, vector<vector<int>> &res){
        if(!root) return;
        
        if(level>res.size())
            res.push_back(vector<int>());
        
        res[level-1].push_back(root->val);
        dfs(root->left, level+1, res);
        dfs(root->right, level+1, res);
    }
};
```

**方法二：BFS**

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
    
    // BFS
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> res;
        if(!root) return res;
        
        queue<TreeNode*> current, next;
        current.push(root);
        vector<int> level;
        
        while(!current.empty()){
            // 先把某一个level的元素全部拿出来
            while(!current.empty()){
                TreeNode* cur = current.front();
                current.pop();
                level.push_back(cur->val);
                if(cur->left) next.push(cur->left);
                if(cur->right) next.push(cur->right);
            }
            res.push_back(level);
            level.clear();
            swap(current,next);
        }
        reverse(res.begin(),res.end());
        return res;
    }
    
};
```