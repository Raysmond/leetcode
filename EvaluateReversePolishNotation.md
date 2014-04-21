Evaluate Reverse Polish Notation
======
##Description
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
```
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
```
##Solution
```cpp
class Solution {
public:
    int convert(string num){
        int result = 0;
        bool negative = false;
        int i=0;
        if(num[0] == '-'){
            negative = true;
            ++i;
        }
        for(;i<num.length();i++){
            result = result * 10 + (int)(num[i] - '0');
        }
        return negative?(0-result):result;
    }
    
    int evalRPN(vector<string> &tokens) {
        stack<int> s;
        int result = 0;
        for(int i=0,size = tokens.size(); i<size;i++){
            string t = tokens[i];
            if(t=="+"){
                int v1 = s.top(); s.pop();
                int v2 = s.top(); s.pop();
                s.push(v2 + v1);
            } else if(t=="-"){
                int v1 = s.top(); s.pop();
                int v2 = s.top(); s.pop();
                s.push(v2 - v1);
            } else if(t=="*"){
                int v1 = s.top(); s.pop();
                int v2 = s.top(); s.pop();
                s.push(v1 * v2);
            } else if(t=="/"){
                int v1 = s.top(); s.pop();
                int v2 = s.top(); s.pop();
                s.push(v2 / v1);
            } else{
                s.push(convert(t));
            }
        }
        return s.top();
    }

};
```