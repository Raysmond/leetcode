Add Binary
====
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".


## Solution
```
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int carry = 0;
        for(int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; --i,--j){
            int abit = i<0 ? 0 : a[i] - '0';
            int bbit = j<0 ? 0 : b[j] - '0';
            int sum = abit + bbit + carry;
            res.insert(res.begin(), '0'+(sum&1));
            carry = sum > 1 ? 1 : 0;
        }
        if(carry>0)
            res.insert(res.begin(),'1');
        return res;
    }
};Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
```