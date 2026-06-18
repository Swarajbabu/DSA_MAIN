#include<iostream>
#include <bits/stdc++.h>
using namespace std;


// Singly Linked List Implementation in C++
// Time Complexity: O(n) for traversing the list 
class Node{
    public:
        int data;
        Node* next;
        
        Node(int value){
            data = value;
            next = NULL;
        }
};

int main(){
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    
    Node* head = first;
    
    first->next = second;
    second->next = third;
    
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data<<" ";
        temp = temp->next;
    }
}
// Output: 10 20 30


// Singly Linked List Cnt and Traversal
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    
    Node(int value){
        data = value;
        next = NULL;
    }
};

int main(){
    
    int cnt = 0;
    
    Node* first = new Node(10);
    Node* second = new Node(11);
    Node* third = new Node(12);
    
    Node* head = first;
    first->next = second;
    second->next = third;
    
    Node* temp = head;
    while(temp!=NULL){
        cnt++;
        temp = temp->next;
    }
    
    Node* temp1 = head;
    while(temp1!=NULL){
        cout << temp1->data<<" ";
        temp1 = temp1->next;
    }
    
    cout<<"\n"<<cnt;
}
// Output: 10 11 12
// 3


// Singly Linked List Creation from Array         Arrays TO Linked List
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        
    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};

void printll(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    int arr[] = {10,20,30,40,50};
    int n = 5;
    
    Node* head = new Node(arr[0]);
    Node* current = head;
    
    for(int i=1;i<n;i++){
        current->next = new Node(arr[i]);
        current = current->next;
    }
    
    printll(head);
}

// Output: 10 20 30 40 50



// Insertion at the Start of the Singly Linked List
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        
    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};

void Insert_at_Start(Node* &head,int add){
   Node* newNode = new Node(add);
   newNode->next = head;
   
   head = newNode;
}

void printll(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    int arr[] = {10,20,30,40,50};
    int n = 5;
    
    Node* head = new Node(arr[0]);
    Node* current = head;
    
    for(int i=1;i<n;i++){
        current->next = new Node(arr[i]);
        current = current->next;
    }
    
    printll(head);
    
    int add = 5;
    cin >> add;
    
    Insert_at_Start(head,add);
    printll(head);
    
}
// Output: 
// 10 20 30 40 50
// 5
// 5 10 20 30 40 50




// Insertion at the End of the Singly Linked List
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};

void Insert_at_End(Node* &head, int add){
    Node* newNode = new Node(add);

    if(head == NULL){
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
}

void printll(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){

    int arr[] = {10,20,30,40,50};
    int n = 5;

    Node* head = new Node(arr[0]);
    Node* current = head;

    for(int i=1;i<n;i++){
        current->next = new Node(arr[i]);
        current = current->next;
    }

    printll(head);

    int add;
    cin >> add;

    Insert_at_End(head, add);

    printll(head);

    return 0;
}
// Output:
// 10 20 30 40 50
// 60
// 10 20 30 40 50 60

// Insertion at the specific position of the Singly Linked List
// Insertion at the Middle of the Singly Linked List
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};

Node* insert_at_specificpos(Node* head,int val,int pos){
    
    Node* newNode = new Node(val);
    newNode->next = NULL;
    
    if(pos == 1)
    {
        newNode->next = head;
        return newNode;
    }
    
    Node* temp = head;
    for(int i=1;i<pos-1;i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp -> next = newNode;
    
    return head;
    
}

void printll(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){

    int arr[] = {10,20,30,40,50};
    int n = 5;

    Node* head = new Node(arr[0]);
    Node* current = head;

    for(int i=1;i<n;i++){
        current->next = new Node(arr[i]);
        current = current->next;
    }

    printll(head);

    int add;
    cin >> add;

    int pos;
    cin >> pos;
    head = insert_at_specificpos(head,add,pos);
    
    printll(head);
    return 0;
}
// Output:
// 10 20 30 40 50
// 25
// 3
// 10 20 25 30 40 50


// Deletion at the Start of the Singly Linked List
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        this->data = val;
        this->next = NULL;
    }
};

// Delete First Node
Node* deleteFirst(Node* head) {

    if(head == NULL) {
        return NULL;
    }

    Node* temp = head;

    head = head->next;

    delete temp;

    return head;
}

// Print Linked List
void printLL(Node* head) {

    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {

    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;

    // Create Linked List
    Node* head = new Node(arr[0]);
    Node* curr = head;

    for(int i = 1; i < n; i++) {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }

    cout << "Before Deletion: ";
    printLL(head);

    head = deleteFirst(head);

    cout << "After Deletion: ";
    printLL(head);

    return 0;
}
// Output:
// Before Deletion: 10 20 30 40 50
// After Deletion: 20 30 40 50

// Deletion at the End of the Singly Linked List
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};

Node* delete_at_end(Node* head){
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    Node* temp = head;
    while(temp->next->next !=NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    
    return head;
}

void printll(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){

    int arr[] = {10,20,30,40,50};
    int n = 5;

    Node* head = new Node(arr[0]);
    Node* current = head;

    for(int i=1;i<n;i++){
        current->next = new Node(arr[i]);
        current = current->next;
    }

    head = delete_at_end(head);
    
    printll(head);
    return 0;
}
// Output:
// 10 20 30 40


// Deletion at the specific position of the Singly Linked List
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node* deleteAtPosition(Node* head, int pos) {

    if(head == NULL)
        return NULL;

    // Delete first node
    if(pos == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;

    // Move to node before the position
    for(int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // Invalid position
    if(temp == NULL || temp->next == NULL) {
        cout << "Invalid Position\n";
        return head;
    }

    Node* nodeToDelete = temp->next;

    temp->next = temp->next->next;

    delete nodeToDelete;

    return head;
}

void printLL(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {

    int arr[] = {10,20,30,40,50};
    int n = 5;

    Node* head = new Node(arr[0]);
    Node* curr = head;

    for(int i = 1; i < n; i++) {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }

    cout << "Before Deletion: ";
    printLL(head);

    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;

    head = deleteAtPosition(head, pos);

    cout << "After Deletion: ";
    printLL(head);

    return 0;
}
// Output:
// Before Deletion: 10 20 30 40 50
// Enter position to delete: 3
// After Deletion: 10 20 40 50

// reverse Linked List
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Reverse Linked List
Node* reverseList(Node* head)
{
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while(curr != NULL)
    {
        next = curr->next;   // Save next node

        curr->next = prev;   // Reverse link

        prev = curr;         // Move prev forward

        curr = next;         // Move curr forward
    }

    return prev;
}

// Print Linked List
void printLL(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;

    // Create Linked List from Array
    Node* head = new Node(arr[0]);
    Node* curr = head;

    for(int i = 1; i < n; i++)
    {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }

    cout << "Original List: ";
    printLL(head);

    head = reverseList(head);

    cout << "Reversed List: ";
    printLL(head);

    return 0;
}