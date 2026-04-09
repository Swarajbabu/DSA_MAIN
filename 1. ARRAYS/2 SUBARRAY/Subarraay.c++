// printing the only sub array index
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void subarray(int arr[],int n){
    int st = 0;
    int ed = n;
    for(int i=st;i<ed;i++){
        for(int j = i;j<ed;j++){
            cout<<"("<<i <<","<<j <<")" ;
        }
        cout<<"\n";
    }
}

int main(){
    int arr[5] = {1,2,3,4,5};
    int n = 5;
    
    subarray(arr,n);
    return 0;
}// o(n^2) T.C. and o(1) S.C.

// output:
// (0,0)(0,1)(0,2)(0,3)(0,4)
// (1,1)(1,2)(1,3)(1,4)
// (2,2)(2,3)(2,4)
// (3,3)(3,4)
// (4,4)

// printing the sub array
#include <iostream>
using namespace std;

void subarray(int arr[],int n){
    int st = 0;
    int ed = n;
    for(int i=st;i<ed;i++){
        for(int j = i;j<ed;j++){
            
            for(int z =i;z<=j;z++){
                cout<<arr[z];
            }
            cout<<" ";
        }
        cout<<"\n";
    }
}

int main()
{
    int arr[5] = {1,2,3,4,5};
    int n = 5;
    
    subarray(arr,n);
    return 0;
}// o(n^3) T.C. and o(n) S.C.

// output:
// 1 12 123 1234 12345 
// 2 23 234 2345 
// 3 34 345 
// 4 45 
// 5 


// maximum sum of sub array of size k
// o(n^2) T.C. and o(1) S.C.  brute force approach
#include <iostream>
using namespace std;

int maxsubarray(int arr[], int k, int n){
    int maxsum = 0;
    
    for(int i=0;i<n-k;i++){
        int sum = 0;
        for(int j = i;j<k+i;j++){
            sum = sum + arr[j];
        }
        maxsum = max(maxsum,sum);
    }
     
    return maxsum;   
}

int main(){
    int arr[] = {1,4,2,10,23,3,1,0,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    
    cout << maxsubarray(arr, k, n);
    return 0;
}
// Input: arr[] = {1,4,2,10,23,3,1,0,20}, k = 4
// output: 39 (10+23+3+1)
// Explanation: Sub-array with maximum sum is {10, 23, 3, 1} with sum as 39.


// maximum sum of sub array of size k   optimal approach using sliding window technique   tc: o(n) and sc: o(1)
class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int wsum = 0;
        for(int i = 0;i<k;i++){
            wsum += arr[i];
        }
        int maxsum = wsum;
        for(int i = k; i < n; i++){
            wsum += arr[i];
            wsum -= arr[i-k];
            
            maxsum = max(maxsum,wsum);
        }
        return maxsum;
    }
};

// Input: arr[] = {1,4,2,10,23,3,1,0,20}, k = 4
// output: 39 (10+23+3+1)



// 1004. Max Consecutive Ones III brute force approach            TC: o(n^2) and SC: o(1)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int max_len = 0;
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j = i;j<n;j++){
                if(nums[j]==0){
                    cnt++;
                }
                if(cnt>k){
                    break;
                }
                max_len = max(max_len,j-i+1);
            }
        }
        return max_len;
    }
};
//                        OR                                  //
// 1004. Max Consecutive Ones III optimal approach using sliding window technique    tc: o(n) and sc: o(1)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        
        int l = 0;
        int cnt = 0;
        for(int r=0;r<n;r++){
            if(nums[r]==0){
                cnt++;
            }
            if(cnt>k){
                if(nums[l]==0){
                    cnt--;
                }
                l++;
            }
        }
        return n-l;
    }
};
// Input: nums = [1,1,1,0,0,0,1,1,1,1], k = 2
// Output: 6



// 713. Subarray Product Less Than K            brute force approach      TC: o(n^2) and SC: o(1)
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int n = nums.size();
        if (k < 1) {
            return 0;
        }
        int mul = 1;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            mul = 1;
            for (int j = i; j < n; j++) {
                mul = mul * nums[j];
                if (mul < k) {
                    cnt++;
                } else {
                    break;
                }
            }
        }
        return cnt;
    }
};
// Input: nums = [10,5,2,6], k = 100
// Output: 8
// Explanation: The 8 subarrays that have product less than 100 are:
// [10], [5], [2], [6], [10,5], [5,2], [2,6], [5,2,6]

//                                or                                 //

// 713. Subarray Product Less Than K            optimal approach using sliding window technique      TC: o(n) and SC: o(1)
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        
        int n  = nums.size();
        int prod = 1;
        int cnt = 0;

        int l = 0;
        for(int r=0; r<n; r++){
            prod = prod * nums[r];
            while(prod >= k){
                prod /= nums[l];
                l++;
            }
            cnt += (r-l+1);
        }
        return cnt;
    }
};
// Input: nums = [10,5,2,6], k = 100
// Output: 8
// Explanation: The 8 subarrays that have product less than 100 are:
// [10], [5], [2], [6], [10,5], [5,2], [2,6], [5,2,6]