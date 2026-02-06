// Selection Sort in C++

#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++){
        int min = i;
        for (int j = i; j < n; j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}

// Output (for input: 64 25 12 22 11):
//         11 12 22 25 64

// bubble sort in C++
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}

// Output (for input: 64 34 25 12 22 11 90):
//         11 12 22 25 34 64 90

// insertion sort in C++
#include <iostream>
using namespace std;
int main(){
    int n, key;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for (int i = 1; i < n; i++){
        key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}

// Output (for input: 12 11 13 5 6):
//         5 6 11 12 13

// Find largest element in an array in C++
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int lrg = arr[0];
    for (int i = 0; i < n; i++){
        if (arr[i] > lrg){
            lrg = arr[i];
        }
    }
    cout << "Largest element in the array is: " << lrg;

    return 0;
}
// Output (for input: 3 5 7 2 8):
//         Largest element in the array is: 8

// Find second largest element in an array in C++
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int lrg = arr[0];
    for (int i = 0; i < n; i++){
        if (arr[i] > lrg){
            lrg = arr[i];
        }
    }

    int sec_largest = -1;
    for (int i = 0; i < n; i++){
        if (arr[i] > sec_largest && arr[i] != lrg){
            sec_largest = arr[i];
        }
    }
    cout << "The second Largest element is: " << sec_largest;

    return 0;
}
// Output (for input: 3 5 7 2 8):
//         The second Largest element is: 7

// Find smallest element in an array in C++
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int min = arr[0];
    for (int i = 0; i < n; i++){
        if (arr[i] < min){
            min = arr[i];
        }
    }
    cout << "The smallest element in array is: " << min;

    return 0;
}
// Output (for input: 3 5 7 2 8):
//         The smallest element in array is: 2

// Find second smallest element in an array in C++
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<int> minAnd2ndMin(vector<int> &arr){
    // code here
    int n = arr.size();
    if (n < 2){
        return {-1};
    }
    int min = INT_MAX;
    int sec_min = INT_MAX;
    for (int i = 0; i < n; i++){
        if (arr[i] < min){
            min = arr[i];
        }
    }
    for (int i = 0; i < n; i++){
        if (arr[i] < sec_min && arr[i] != min){
            sec_min = arr[i];
        }
    }
    if (sec_min == INT_MAX){
        return {-1};
    }
    return {min, sec_min};
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> result = minAnd2ndMin(arr);
    if (result.size() == 1 && result[0] == -1){
        cout << "No second smallest element";
    }
    else{
        cout << "The second smallest element is: " << result[1];
    }
    return 0;
}
// tc = O(2n)  // sc = O(1)
// Output (for input: 3 5 7 2 8):
//         The second smallest element is: 3



// Reverse an Array in C++
void reverseArray(vector<int> &arr) {
        // Two pointer approach
    int n = arr.size();
    int start = 0;
    int end = n-1;
    while(start<end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    reverseArray(arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
// Output (for input: 1 2 3 4 5):
//         5 4 3 2 1


// check if array is sorted or not in C++pp[                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              ]
#include <iostream>
using namespace std;
bool isSorted(vector<int> &arr){
    // code here
    int n = arr.size();
    if (n <= 1){
        return true;
    }
    for (int i = 1; i < n; i++){
        if (arr[i] < arr[i - 1]){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    if (isSorted(arr)){
        cout << "1";
    }
    else{
        cout << "0";
    }
    return 0;
}

// Output (for input: 1 2 3 4 5):
//         1
// Output (for input: 5 3 2 4 1):
//         0



// Remove Duplicates from Sorted Array in C++
// 2 pointers approach
#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    int i = 0;
    for (int j = 1; j < n; j++) {
        if (nums[i] != nums[j]) {
            nums[i + 1] = nums[j];
            i++;
        }
    }
    return i + 1; 
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k = removeDuplicates(nums);
    cout << "The length of array after removing duplicates is: " << k << endl;

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}

// Output (for input: 1 1 2 2 3 3 3 4 8 9):
//         The length of array after removing duplicates is: 6


// Left Rotate an Array by One in C++
#include <iostream>
using namespace std;
void left_rotate_arr(int arr[],int n){
    int temp = arr[0];
    for(int i=1;i<n;i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    left_rotate_arr(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

// Output (for input: 1 2 3 4 5):
//         2 3 4 5 1

// Right Rotate an Array by One in C++
void Rigtht_1_rotate(vector<int> &arr) {
    // code here
    int n = arr.size();
    int temp = arr[n-1];
    for(int i = n-1;i>0;i--){
        arr[i] = arr[i-1];
    }
    arr[0] = temp; 
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Rigtht_1_rotate(arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

// Output (for input: 1 2 3 4 5):
//         5 1 2 3 4


// right Rotate an Array by K times in C++
#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int>& nums, int k) {
    k = k % nums.size();
    for(int i=0; i<k; i++){
        int temp = nums[nums.size()-1];
        for(int i=nums.size()-1;i>0;i--){
            nums[i] = nums[i-1];
        } 
        nums[0]= temp;
    }
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    rotate(arr,k);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
// Output (for input: 1 2 3 4 5 and k=2):
//         4 5 1 2 3


// right Rotate an Array by K times - Optimized Approach in C++
class Solution {
public:
    void arrrot(vector<int>& arr,int st,int ed){
        while(st<ed){
            int temp = arr[st];
            arr[st] = arr[ed];
            arr[ed] = temp;
            st++;
            ed--;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % nums.size();
        
        arrrot(nums,0,n-1-k);
        arrrot(nums,n-k,n-1);
        arrrot(nums,0,n-1);
    }
};
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Solution sol;
    sol.rotate(arr,k);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
// Output (for input: 1 2 3 4 5 and k=2):
//         4 5 1 2 3



// Linear Search in C++
int search(vector<int>& arr, int x) {
    // code here
    int n = arr.size();
    for(int i=0;i<n;i++){
        if(arr[i] == x){
            return i;
        }
    }
    return -1;
}
int main(){
    int n,x;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}

// Output (for input: 4 2 3 5 6 and x=5):
//         2


// Move all zeros to end of array in C++
//pointer approach to move all zeros to end of array in C++
void moveZeroes(vector<int>& arr) {
    int n = arr.size();
    int j = 0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    moveZeroes(arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
// Output (for input: 0 1 0 3 12):
//         1 3 12 0 0
// output (for input: 5 2 9 0 6 0 7 0 1):
//         5 2 9 6 7 1 0 0 0


// Find the Missing Number in C++
class Solution1 {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int nm = (n*(n+1))/2;
        int sum = 0;
        for(int i = 0 ;i<n ;i++){
            sum = sum + nums[i];
        }
        return nm-sum;
    }
};
int main(){
    int n;
    cin>>n;
    vector<int> arr(n-1);
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }
    Solution1 sol;
    int missing = sol.missingNumber(arr);
    cout<<"The missing number is: "<<missing;
    return 0;
}
// Output (for input: 0 1 3):
//         The missing number is: 2
// explanation: n=3 so numbers are from 0 to 3. 2 is missing. total 4 numbers
