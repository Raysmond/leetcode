Plus One
======

##Description
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
##Solution
```cpp
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 0, n = digits.size();
        digits[n-1]++;
        for(int i=n-1;i>=0;--i){
            if(carry + digits[i] >= 10){
                digits[i] = (digits[i]+carry)%10;
                carry = 1;
            } else{
                digits[i]+=carry;
                carry = 0;
                break;
            }
        }
        if(carry>0) digits.insert(digits.begin(),1);
        return digits;
    }
};
```