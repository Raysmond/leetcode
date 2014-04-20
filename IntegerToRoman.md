Integer to Roman
=====

##Description
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

##Solution
```cpp
class Solution {
public:
    string intToRoman(int num) {
        string roman[4][10] = {{"","I","II","III","IV","V","VI","VII","VIII","IX"},
                               {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
                               {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
                               {"","M","MM","MMM"}
                              };
        string res = "";
        int n = num, count = 0;
        while(n>0){
            res = roman[count++][n%10] + res;
            n/=10;
        }
        return res;
    }
};
```