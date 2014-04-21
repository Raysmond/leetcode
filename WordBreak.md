Word Break
======

##Description
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

##Solution
```cpp
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int len = s.length();
        //dp[i]表示dp[i:n]这段字符串可以分解为dict中的单词
        vector<bool> dp(len + 1, false); 
        dp[len] = true;
        for(int i= len - 1;i>=0;i--){
            for(int j = i;j<len;j++){
                string str = s.substr(i, j - i + 1);
                if(dict.find(str)!=dict.end() && dp[j+1]){
                    dp[i] = true;
                }
            }
        }
        return dp[0];
    }
};
```