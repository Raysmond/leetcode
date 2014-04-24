Permutations
======

##Description
Given a collection of numbers, return all possible permutations.

For example,
`[1,2,3]` have the following permutations:
`[1,2,3]`, `[1,3,2]`, `[2,1,3]`, `[2,3,1]`, `[3,1,2]`, and `[3,2,1]`.

##Solution
递归，每次把元素放到最后一个

```cpp
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> res;
        permuteRe(res,num,num.size());
        return res;
    }
    
    void permuteRe(vector<vector<int>> &res, vector<int> &num,int n){
        if(n==0){
            res.push_back(num);
            return;
        }
        for(int i=0;i<n;++i){
            swap(num[i],num[n-1]);
            permuteRe(res,num,n-1);
            swap(num[i],num[n-1]);
        }
    }
};
```