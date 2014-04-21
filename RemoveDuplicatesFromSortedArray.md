Remove Duplicates from Sorted Array
=======

##Description
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].
##Solution
```cpp
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int m = 0;
        for(int i=0;i<n;++i){
            if(i==0 || A[i] != A[i-1])
                A[m++] = A[i];
        }
        return m;
    }
};
```
