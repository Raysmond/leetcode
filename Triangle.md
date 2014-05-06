Triangle
=====

##Description
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
```
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
```
The minimum path sum from top to bottom is 11 (i.e., `2 + 3 + 5 + 1 = 11`).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
##Solution
`dp`

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        vector<int> dp(triangle.size(), 0);
        for(int i=0;i<triangle.size();++i){
            if(i==0) dp[0] = triangle[i][0];
            else for(int j=i;j>=0;--j){
                if(j==0) dp[0] += triangle[i][j];
                else if(j==i) dp[j] = dp[j-1] +  triangle[i][j];
                else dp[j] = triangle[i][j] + (dp[j-1] < dp[j] ? dp[j-1] : dp[j]);
            }
        }
        int min = dp[0];
        for(int i=1;i<dp.size();++i){
            if(dp[i] < min)
                min = dp[i];
        }
        return min;
    }
};
```