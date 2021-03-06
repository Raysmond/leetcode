Container With Most Water
=======

##Description
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.

##Solution
```cpp
class Solution {
public:
    int maxArea(vector<int> &height) {
        int res;
        int left =0, right = height.size()-1;
        while(left<right){
            if(height[left]<=height[right]){
                res = max(res, (right-left)*height[left]);
                left++;
            } else{
                res = max(res, (right-left)*height[right]);
                right--;
            }
        }
        return res;
    }
};
```