// 1266. Minimum Time Visiting All Points 13-01-2026
// working and explanation: The idea is to move diagonally as much as possible
// taking max of x and y difference at each step
// since in one second we can move in both x and y direction simultaneously
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0; 
        int n = points.size();
        for(int i = 1;i<n;i++){
            ans = ans + max(abs(points[i][0]-points[i-1][0]),
                            abs(points[i][1]-points[i-1][1]));
        }
        return ans;
    }
};
// Output (for input: points = [[1,1],[3,4],[-1,0]]):
//         7

// Output (for input: points = [[3,2],[-2,2]]):
//         5

// LeetCode Problem: Majority Element
int majorityElement(vector<int>& nums) {
    unordered_map<int,int> mpp;
    int n = nums.size();
    for(int i = 0;i<n;i++){
        mpp[nums[i]]++;     
    }
    for(auto it: mpp){
        if(it.second > (n/2)){
            return it.first;
        }
    }
    return -1;
}
//output (for input: nums = [3,2,3]):
//         3