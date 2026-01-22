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


class Solution {
public:
    // find minimum sum pair of adjacent elements and index
    int minum(vector<int>& nums){
        int minsum = INT_MAX;
        int indux = -1;
        for(int i = 0;i<nums.size()-1;i++){
            if(nums[i]+nums[i+1] < minsum){
                indux = i;
                minsum = nums[i]+nums[i+1];
            }
        }
        return indux;
    }
    // main function to find minimum pair removal to make array sorted
    int minimumPairRemoval(vector<int>& nums) {
        int cun = 0;
        while(!is_sorted(begin(nums),end(nums))){
            int indux = minum(nums);
            nums[indux] = nums[indux]+nums[indux+1];
            nums.erase(begin(nums)+indux+1);
            cun++;
        }
        return cun;
    }
};
// [5,2,3,1]
// 2

// [1,2,2]
// 0

