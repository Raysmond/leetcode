Roman to Integer
=====

##Description
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

##Solution
罗马数字到十进制转换时只要把对应的数字相加就行了，除了一条规则，左边比右边小的时候，是减去左边，如IV，就是5-1。算法就是一直累加，碰到左边比右边小时，则做减法。
```cpp
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> roman;
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;
        
        int result = 0, n = s.length();
        for(int i=0;i<n;++i){
            if(i<n-1 && roman[s[i]] < roman[s[i+1]])
                result -= roman[s[i]];
            else result += roman[s[i]];
        }
        return result;
    }
};
```