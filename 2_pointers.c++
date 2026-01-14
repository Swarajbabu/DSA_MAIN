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