Single Number II
=======
##Description
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

##Solution
所有的数字从二进制的角度来看，第i个bit相加后对3取余等于0或1，等于1时说明这个bit出现在那个唯一出现一次的数字中。

```php
class Solution {
public:
    int singleNumber(int A[], int n) {
        int ret = 0;
        for(int i= 0; i< 32; i++){
            int tmp = 0;
            for(int j = 0; j < n; j++){
                tmp+=((A[j]>>i)&1);
            }
            ret |= ((tmp%3)<<i);
        }
        return ret;
    }
};
```