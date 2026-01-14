// hashing technique to count frequency of elements in an array
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    int hash[13] = {0};
    for(int i = 0;i<n;i++){
        hash[arr[i]] += 1;
    }
    int val;
    cin>>val;
    while(val--){
        int num;
        cin>>num;
        cout<<hash[num]<<" ";
    }
}
// Output (for input: 7 1 2 3 2 3 4 3 3 2 5):
//         3 2 1


// hashing technique to count frequency of characters in a string
#include<iostream>
using namespace std;
int main(){
    string name;
    cin >> name;
    
    int hash[26] = {0};
    for(int i = 0;i<name.size();i++){
        hash[name[i] - 'a'] ++;
    }
    int val;
    cin>>val;
    while(val--){
        char ch;
        cin>>ch;
        cout<<hash[ch-'a']<<" ";
    }
}
//explaction: for character 'a', index will be 0, for 'b' index will be 1 and so on...
//if we dont - 'a', then for character 'a' index will be 97(ascii value of 'a' is 97)
// which is out of bound for hash array of size 26

// Output (for input: swarajbabu 3 a b z):
//         3 2 0


// hashing technique to count frequency of characters in a string with uppercase and lowercase
#include<iostream>
using namespace std;
int main(){
    string name;
    cin >> name;
    
    int hash[256] = {0};
    for(int i = 0;i<name.size();i++){
        hash[name[i]] ++;
    }
    int val;
    cin>>val;
    while(val--){
        char ch;
        cin>>ch;
        cout<<hash[ch]<<" ";
    }
}
//explaction: here we are using hash array of size 256 to accomodate both uppercase and lowercase characters
// ascii value of 'A' is 65 and 'Z' is 90
// ascii value of 'a' is 97 and 'z' is 122
// so we need larger size array to accomodate all characters


// Output (for input: SwaraJBabu 4 a B z S):
//         3 1 0 1


// hashing technique to count frequency of elements in an array using map
// more flexible than array as it can handle larger range of elements
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    
    map<int,int> mpp;
    for(int i =0 ;i<n;i++){
        mpp[arr[i]]++;
    }
    
    //printing values in map;
    for(auto it : mpp){
        cout<<it.first << "->" << it.second<<"\n";
    }
    
    int val;
    cin>>val;
    cout<< mpp[val]<<" ";
}
// Output (for input: 7 1 2 3 2 3 4 3 3 2 5):
//         1->1
//         2->2
//         3->3
//         4->1
//         3
//         3
// hashing technique to count frequency of characters in a string using map

// more flexible than array as it can handle larger range of characters
#include<bits/stdc++.h>
using namespace std;
int main(){
    string n;
    cin>>n;
    
    map<char,int> mpp;
    for(int i = 0 ;i<n.size();i++){
        mpp[n[i]]++;
    }
    
    //printing values in map;
    for(auto it : mpp){
        cout<<it.first << "->" << it.second<<"\n";
    }
    
    char s;
    cin>>s;
    cout<< mpp[s]<<" ";
    
}
// Output (for input: SwaraJBabu a):
//         A->1
//         B->1
//         J->1
//         S->1
//         a->3
//         b->2
//         r->1
//         u->1
//         3
// map stores elements in sorted order based on keys    


// LeetCode Problem: Two Sum
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> mpp;
    int n = nums.size();
    for(int i=0;i<n;i++){
        int need = target - nums[i];
        if(mpp.find(need) != mpp.end()){
            return {mpp[need],i};
        }
        mpp[nums[i]] = i; 
    }
    return {};
}
// Explanation: We use a map to store the elements we have seen so far along with their indices.
// For each element, we calculate the complement (need) that would sum up to the target.
// If the complement is found in the map, we return the indices of the complement and the current element.
// If not found, we store the current element and its index in the map for future reference.
// output (for input: nums = [2,7,11,15], target = 17):
//         [0,3]


// LeetCode Problem: Contains Duplicate
bool containsDuplicate(vector<int>& nums) {
    unordered_map<int,int> mpp;
    int n = nums.size();
    for(int i=0;i<n;i++){
        if(mpp.find(nums[i])!=mpp.end()){
            return true;
        }
        mpp[nums[i]] = i;
    }
    return false;
};
//output (for input: nums = [1,2,3,1]):
//         true


bool containsDuplicate(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[nums[i]]++;
        if(mpp[nums[i]]>1){
            return true;
        }
    }
    return false;
}
//output (for input: nums = [1,2,3,1]):
//         true

// Using unordered_set but it wont allow duplicate elements
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> s;
    int n = nums.size();
    for(int i=0;i<n;i++){
        if(s.find(nums[i])!=s.end()){
            return true;
        }
        s.insert(nums[i]);
    }
}
//output (for input: nums = [1,2,3,1]):
//         true

bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int n = nums.size();
    for(int i=1;i<n;i++){
        if(nums[i]==nums[i-1]){
            return true;
        }
    }
    return false;
}
//output (for input: nums = [1,2,3,1]):
//sorted array will be [1,1,2,3]
//checking adjacent elements
//         true


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


