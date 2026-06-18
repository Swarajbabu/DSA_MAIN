#include <bits/stdc++.h>
using namespace std;


//  * Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

// 876 Find the Middle of the Linked List           O(n) time complexity and O(1) space complexity 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        
        ListNode* temp1 = head;
        ListNode* Val;
        int ccnt = cnt/2;
        int pcnt = 0;
        while(temp1 != NULL){
            if(pcnt == ccnt){
                Val = temp1; 
                break;
            }else{
                pcnt++;
            }
            temp1 = temp1->next;
        }
        return Val;
    }
};
// Input: head = [1,2,3,4,5]
// Output: [3,4,5]


// 206 Reverse Linked List
//Definition for singly-linked list.
struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]