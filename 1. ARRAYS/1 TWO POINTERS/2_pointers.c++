// Reverse an array using two pointers //gfg
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void reverse_array(vector<int> &arr){
    int n = arr.size();
    int st = 0;
    int ed = n-1;
    while(st<ed){
        swap(arr[st],arr[ed]);
        st++;
        ed--;
    }
};
// Output (for input: 1 2 3 4 5):
//         5 4 3 2 1


// Reverse a string using two pointers leetcode
void reverseString(vector<char>& s) {
    int n = s.size();
    int st = 0;
    int ed = n-1;
    while(st<ed){
        swap(s[st],s[ed]);
        st++;
        ed--;
    }
};
// Output (for input: h e l l o):
//         o l l e h
// Output (for input: SWARAJBABU):
//         UBABJARAWS


// Find Maximum Consecutive Ones in an array in C++ leetcode
#include<bits/stdc++.h>
using namespace std;
int findMaxConsecutiveOnes(vector<int>& nums) {
    int n = nums.size();
    int max1 = 0;
    int cnt = 0;
    for(int i = 0;i<n ;i++){
        if(nums[i]==1){
            cnt++;
            max1 = max(max1,cnt);
        }
        else{
            cnt = 0;
        }
    }
    return max1;
};
// Output (for input: 1 1 0 1 1 1):
//         3


// Segregate 0s and 1s in an array leetcode
class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int i = 0;
        int j = arr.size()-1;
        while(i<j){
            if(arr[i]==0){
                i++;
            }
            else if(arr[j]==1){
                j--;
            }
            else{
                swap(arr[i],arr[j]);
                i++;
                j--;
            }
        }
    }
};
// Output (for input: 0 1 0 1 1 0):
//         0 0 0 1 1 1


// 167. Two Sum II - Input Array Is Sorted TC O(n) SC O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int a = 0;
        int b = numbers.size()-1;
        while(a<b){
            int sum = numbers[a]+numbers[b]; 
            if(sum==target){
                return {a+1,b+1};
            }
            else if(numbers[a]+numbers[b]<target){
                a++;
            }
            else{
                b--;
            }
        }
        return {};
    }
};
// Input: numbers = [2,7,11,15], target = 9
// Output: [1,2]

// Input: numbers = [2,3,4], target = 6
// Output: [1,3]
//


// “at most 1 duplicate” → compare with nums[i-1]
// “at most 2 duplicates” → compare with nums[i-2]
// “at most k duplicates” → compare with nums[i-k]

// 26. Remove Duplicates from Sorted Array
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        int i = 0;
        for(int j = 1;j < n;j++){
            if(nums[j] != nums[i]){
                nums[i+1] = nums[j];
                i++;
            }
        }
        return i+1;
    }
};
// Input: nums = [0,0,1,1,1,2,2,3,3,4]
// Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]


// 80. Remove Duplicates from Sorted Array II

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n<=2) return n;
        int i = 2;
        for(int j=2;j<n;j++){
            if(nums[j]!=nums[i-2]){
                nums[i]=nums[j];
                i++;
            }
        }
        return i;
    }
};

// Input: nums = [0,0,1,1,1,1,2,3,3]
// Output: 7, nums = [0,0,1,1,2,3,3,_,_]


// Stacks using array
class Solution {
public:
    int binaryGap(int n) {
        string B = bitset<32>(n).to_string();

        int last = -1;
        int ans = 0;

        for(int i = 0; i < B.length(); i++) {
            if(B[i] == '1') {
                if(last != -1) {
                    ans = max(ans, i - last);
                }
                last = i;
            }
        }

        return ans;
    }
};
// Input: n = 22
// Output: 2
// explanation: 22 in binary is "10110". In the binary representation of 22, there are three ones, 
// and the two consecutive pairs of 1's have distances 2 and 1. The maximum distance is 2. 
// Hence the answer is 2.


// 15. 3Sum
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue; 

            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum>0){
                    k--;
                }
                else if(sum<0){
                    j++;
                }
                else{
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    k--;
                    j++;

                    //it was running fine but the dublates are there for k and j
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
            }

        }
        return ans;
    }
};

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]

//explanation: The given array is [-1,0,1,2,-1,-4]. After sorting the array becomes [-4,-1,-1,0,1,2].
// The triplets that sum up to zero are:
// [-1,-1,2] and [-1,0,1]. Note that the order of the output and the order of the triplets does not matter.



// 75. Sort Colors
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int mid = 0;
        int hig = n-1;

        while(mid<=hig){
            if(nums[mid]==1){
                mid++;
            }
            else if(nums[mid]==0){
                int temp = nums[mid];
                nums[mid] = nums[low];
                nums[low] = temp;
                mid++;
                low++;
            }
            else{
                int temp = nums[mid];
                nums[mid] = nums[hig];
                nums[hig] = temp;

                hig--;
            }
        }
    }
};

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
// Explanation: The given array is [2,0,2,1,1,0]. After sorting the array becomes [0,0,1,1,2,2].


// 11. Container With Most Water
class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n = height.size();
        // if(n < 1) return 0;
        int l = 0;
        int r = n-1;

        int mxarea = 0;
        while(l<r){
            int len = min(height[l],height[r]);
            int wid = r-l;
            int area = len*wid;
            mxarea = max(mxarea,area);

            if(height[l]>=height[r]) r--;
            else l++;
        }
        return mxarea;

    }
};
// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.


// 42. Trapping Rain Water
class Solution {
public:
    int trap(vector<int>& height) {
        int  n = height.size();
        int left = 0;
        int right = n-1;

        int leftmax = height[left];
        int rightmax = height[right];

        int water = 0;

        while(left<right){ 
            if(leftmax < rightmax){
                left++;
                leftmax = max(leftmax,height[left]);
                water += leftmax - height[left]; 
            }
            else{
                right--;
                rightmax = max(rightmax,height[right]);
                water += rightmax - height[right];
            }
        }

        return water;
    }
};

// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
