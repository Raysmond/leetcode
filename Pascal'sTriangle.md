Pascal's Triangle 
======

##Description
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return
```
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
```

##Solution

```cpp
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> res;
        for(int i=0;i<numRows;i++){
            vector<int> ares;
            res.push_back(ares);
            for(int j=0;j<i+1;++j){
                if(j==0 || j==i){
                    res[i].push_back(1);
                } else {
                    res[i].push_back(res[i-1][j-1]+res[i-1][j]);
                }
            }
        }
        return res;
    }
};
```