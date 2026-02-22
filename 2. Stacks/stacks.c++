// 
#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack <int> s;
    
    s.push(1);
    s.push(2);
    s.push(30);
 
    cout<<s.top()<<" ";
    cout<<s.size()<<" ";
    
    cout<<s.empty();
    return 0;
}


// Stacks using class 
#include <iostream>
#include <vector>
using namespace std;

class MyStack{
    vector<int> v;
    
    public:
    
    void push(int val){
        v.push_back(val);    
    }
    
    void pop(){
        v.pop_back();
    }
    
    int top(){
        return v[v.size()-1];
    }
    bool empty(){
        return v.size()==0;
    }
};
int main(){
    MyStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}

// Stacks using array
#include<iostream>
#include<stack>
using namespace std;

int arr[5];
int topval = -1;
void push(int val){
    if(topval==4){
        cout<<"Stack is full";
        return;
    }
    arr[++topval] = val;
    
}
void pop(){
    if(topval==-1){
        cout<<"Stake is eampty";
    }
    topval--;
}
int top(){
    return arr[topval];
}
bool empty(){
    return topval==-1;
}
    
int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    while(!empty()){
        cout<< arr[topval]<<" ";
        pop();
    }
}

// inserting an stack at bottom of the container
#include<iostream>
#include<stack>
using namespace std;
void insert_at_bottem(stack<int> &s,int val){
    if(s.empty()){
        s.push(val);
        return;
    }
    int temp = s.top();
    s.pop();
    insert_at_bottem(s,val);
    s.push(temp);
}

int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    insert_at_bottem(s,50);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}
// Output  50 10 20 30
//In the quatation we are using an recursive function to insert an element at the bottom of the stack 
// and doing backtracking to push the other elements

// Reversing a string using stack
#include<iostream>
#include<stack>
#include<string>
using namespace std;

string stringrev(stack<char> &s,string name){
    string newStr = "";
    for(int i=0;i<name.size();i++){
        s.push(name[i]);
    }
    
    while(!s.empty()){
        newStr += s.top();
        s.pop();
    }
    return newStr;
}

int main(){
    stack<char> s;
    string name = "swaraj";
    
    cout<<"THE REVERSE OF STRING: "<<stringrev(s,name);
}


// Reversing a stack using recursion
#include<iostream>
#include<stack>
#include<string>
using namespace std;

void insert_at_bottem(stack<int> &s,int val){
    if(s.empty()){
        s.push(val);
        return;
    }
    int temp = s.top();
    s.pop();
    insert_at_bottem(s,val);
    
    s.push(temp);
}
void reverse(stack<int> &s){
    if (s.empty()) {
        return;
    }
    int temp = s.top();
    s.pop();
    reverse(s);
    insert_at_bottem(s,temp);
    
}
int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}
// Original Stack (Top → Bottom): 10 20 30
// Reversed Stack (Top → Bottom): 30 20 10