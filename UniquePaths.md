Unique Paths
======

##Description
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Note: m and n will be at most 100.
##Solution
C(m+n-2,m-1) or C(m+n-2,n-1)

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 || n==1) return 1;
        int s = m + n - 2;
        int t = m > n ? (m-1) : (n-1);
        long long res = 1;
        for(int i=s;i>t;i--)
            res *= i;
        for(int i=s-t;i>1;i--)
            res /= i;
        return res;
    }
};
```

