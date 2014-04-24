Generate Parentheses
=======

##Description
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

`"((()))"`, `"(()())"`, `"(())()"`, `"()(())"`, `"()()()"`
##Solution
```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParenthesisRe(n,n,"",res);
        return res;
    }
    void generateParenthesisRe(int left,int right,string s,vector<string> &res){
        if(left == 0 && right == 0){
            res.push_back(s);
            return;
        }
        if(left>0)
            generateParenthesisRe(left-1,right,s+"(",res);
        if(right>left)
            generateParenthesisRe(left,right-1,s+")",res);
    }
};
```