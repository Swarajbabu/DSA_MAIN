
// C++ program to print "Swaraj" n times using recursion
#include <iostream>
using namespace std;

void nam(int i,int n){
    if(i>=n){
        return;
    }
    cout<<"Swaraj\n";
    i++;
    nam(i,n);
}
int main(){
    int n;
    cin>>n;
    
    int i=0;
    nam(i,n);
}

// Output (for input: 5):
//         Swaraj upto 5 times


// C++ program to print first n natural numbers using recursion
#include <iostream>
using namespace std;

void nam(int i,int n){
    if(i>n){
        return;
    }
    cout<<i<<" ";
    i++;
    nam(i,n);
}
int main(){
    int n;
    cin>>n;
    
    int i=1;
    nam(i,n);
}
// Output (for input: 5):
//         1 2 3 4 5

