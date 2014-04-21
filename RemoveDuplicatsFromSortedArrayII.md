Remove Duplicates from Sorted Array II
=======

##Description
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].
##Solution
```cpp
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int m = 0;
        int dup = 0;
        for(int i=0;i<n;++i){
            if(i==0 || A[i]!=A[i-1]){
                A[m++] = A[i];
                dup = 0;
            }
            else if(dup++==0){
                A[m++] = A[i];
            }
        }
        return m;
    }
};
```
