Two Sum
========
##Description
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: `numbers={2, 7, 11, 15}, target=9`
Output: `index1=1, index2=2`

##Solution
- Solution one
`Hash`
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> hash(target/2+1, -1);
        vector<int> res;
        int minIndex = 0,min = 0;
        
        // Find the smallest number
        for (int i=1; i<numbers.size(); ++i) {
            if(numbers[i]<numbers[minIndex])
                minIndex = i;
        }
        min = numbers[minIndex];
        if(min<0){
            target -= (2 * min);
            for (int i=0; i<numbers.size(); ++i) {
                numbers[i]-= min;
            }
        }
       
        for(int i=0, half = target/2;i<numbers.size();++i){
            // if a + b = target, then a,b will hashed into the same bucket
            int hit = numbers[i] <= half ? numbers[i] : target - numbers[i];
            if(hit<0) continue;
            if(hash[hit]==-1) hash[hit] = i;
            else if(numbers[hash[hit]]+numbers[i] == target){
                res.push_back(hash[hit]+1);
                res.push_back(i+1);
                break;
            }
        }
        return res;
    }
};
```

- Solution two
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target){
        unordered_map<int,int> dict;
        unordered_map<int,int>::const_iterator idx;
        vector<int> res;
        for(int i=0;i<numbers.size();++i){
            idx = dict.find(target - numbers[i]);
            if(idx!=dict.end()){
                res.push_back(idx->second+1);
                res.push_back(i+1);
                break;
            } else dict[numbers[i]] = i;
        }
        return res;
    }
};
```