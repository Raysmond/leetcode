Pascal's Triangle II
=========
Given an index k, return the kth row of the Pascal's triangle.

For example, given `k = 3`,
Return `[1,3,3,1]`.

Note:
Could you optimize your algorithm to use only O(k) extra space?

##Description

##Solution
```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1,1);
        vector<int> tmp(rowIndex+1,1);
        for(int i=2;i<=rowIndex;++i){
            for(int j=1;j<i;++j)
                res[j] = tmp[j-1] + tmp[j];
            for(int j=1;j<i;++j)
                tmp[j] = res[j];
        }
        return res;
    }
};
```