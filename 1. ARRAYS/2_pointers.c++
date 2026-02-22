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
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    reverse_array(arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
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
}
int main(){
    int n;
    cin>>n;
    vector<char> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    reverseString(arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
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
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<findMaxConsecutiveOnes(arr);
    return 0;
}
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
    
        int k = 2;    
        if (nums.size() <= 2) return nums.size(); 
        for(int i = 2 ;i < nums.size(); i++){
            if(nums[i] != nums[k-2]){
                nums[k] = nums[i];
                k += 1;
            }
        }
        return k;

    }
};
// or
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