Climbing Stairs
======

##Description
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

##Solution
```cpp
class Solution {
public:
    int climbStairs(int n) {
        if(n==0||n==1||n==2) return n;
        int s1 = 1, s2 = 2, s3 = 0;
        for(int i = 3; i<=n; i++){
            s3 = s2 + s1;
            s1 = s2;
            s2 = s3;
        }
        return s3;
    }
};
```