Valid Number
====

Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.


## Solution

```cpp
class Solution {
public:
    
    bool isNumber(const char *s) {
        bool e = false;
        bool dot = false;
        
        const char *p = s;
        while(isspace(*p)) p++;
        if(*p=='\0') return false;
        if(*p=='+' || *p == '-') p++;
        
        const char *head = p;
        while(*p!='\0'){
            if(*p=='e') {
                if(e || head == p) return false;
                e = true;
                p++;
                if(*p == '+' || *p == '-') p++;
                if(!isdigit(*p)) return false;
                continue;
            }
            if(*p=='.'){
                if(dot || e || (head == p && !isdigit(*(p+1)) )) return false;
                dot = true;
                p++;
                continue;
            }
            
            if(isspace(*p)){
                while(*p!='\0'){
                    if(!isspace(*p)) return false;
                    p++;
                }
                return true;
            }
            
            if(!isdigit(*p))
                return false;
            
            p++;
        }
        return true;
    }
};
```