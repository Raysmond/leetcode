// Source: https://oj.leetcode.com/problems/triangle/

/*
 * Triangle
 *
 * Given a triangle, find the minimum path sum from top to bottom. 
 * Each step you may move to adjacent numbers on the row below.
 *
 * For example, given the following triangle
 * [
 *      [2],
 *     [3,4],
 *    [6,5,7],
 *   [4,1,8,3]
 * ]
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 *
 * Note:
 * Bonus point if you are able to do this using only O(n) extra space, where n is the total number 
 * of rows in the triangle.
 */

//
//  main.cpp
//  triangle
//
//  Created by Raysmond on 27/10/14.
//  Copyright (c) 2014 Raysmond. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        vector<int> dp(triangle.size(), 0);
        for(int i=0;i<triangle.size();++i){
            if(i==0) dp[0] = triangle[0][0];
            else{
                int tmp = 0, tmpOld = 0;
                for(int j=0;j<=i;++j){
                    tmp = dp[j];
                    if(j==0) dp[j] += triangle[i][j];
                    else if(j==i) dp[j] = triangle[i][j] + tmpOld;
                    else{
                        dp[j] = triangle[i][j] + min(tmpOld,dp[j]);
                    }
                    tmpOld = tmp;
                }
            }
        }
        int min = dp[0];
        for(int i=0;i<dp.size();++i)
            if(dp[i]<min)
                min = dp[i];
        return min;
    }
};

int main(int argc, const char * argv[])
{

    vector<vector<int>> input;
    vector<int> v1{-1};
    vector<int> v2{-2,-3};
    input.push_back(v1);
    input.push_back(v2);
    Solution s;
    cout<<s.minimumTotal(input)<<endl;
    return 0;
}

