// printing the only sub array index
#include <iostream>
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