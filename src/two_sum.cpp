// Source : https://oj.leetcode.com/problems/two-sum/

/******************************************
* Two Sum
*
* Given an array of integers, find two numbers such that they add up to a specific target number.
*
* The function twoSum should return indices of the two numbers such that they add up to the target, 
* where index1 must be less than index2. Please note that your returned answers (both index1 and
* index2) are not zero-based.
*
* You may assume that each input would have exactly one solution.
*
* Input: numbers={2, 7, 11, 15}, target=9
* Output: index1=1, index2=2
*
* Solution: hash
*******************************************/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int,int> m;
        vector<int> res;
        for(int i=0;i<numbers.size();++i){
            if(m.find(numbers[i]) != m.end()){
                res.push_back(m[numbers[i]]+1);
                res.push_back(i+1);
            } else {
                m[target-numbers[i]] = i;
            }
        }
        return res;
    }
};

int main(){
  // Solution s;
  // vector<int> arr{2,7,11,15}; 
  // vector<int> res = s.twoSum(arr, 9);
  // cout<<res[0]<<" "<<res[1]<<endl;
  // return 0;
}