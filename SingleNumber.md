Single Number
========

## Description
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

## Solution

```cpp
class Solution {
public:
    int singleNumber(int A[], int n) {
        int ret = A[0];
        for(int i=1;i<n;++i){
            ret = ret ^ A[i];
        }
        return ret;
    }
};
```