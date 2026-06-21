#include <bits/stdc++.h>
using namespace std;


//  * Definition for singly-linked list.              Br
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

// 876 Find the Middle of the Linked List           BRUTE FORCE SOLUTION  O(n) TC and O(n) SC 
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

// 876 Find the Middle of the Linked List           OPTIMAL SOLUTION  O(n) TC and O(1) SC
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};


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


// 19 Remove Nth Node From End of List
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode* temp = head;
        
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        int reqint = cnt - n + 1;

        if(reqint == 1){
            ListNode* newDell = head;
            head = head->next;
            delete newDell;
            return head;
        }

        ListNode* temp1 = head;
        for(int i= 1;i<(reqint - 1);i++){
            temp1 = temp1->next;
        }
        ListNode* newDel = temp1->next;
        temp1->next = temp1->next->next;
        delete newDel;
        return head;
    }
};
// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]
// Explanation: Given n will always be valid. 1 ≤ n ≤ sz, where sz is the size of the linked list.


// 141 Linked List Cycle                     TC O(n) and SC O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(fast==slow){
                return true;
            }
        }

        return false;
    }
};
// Input: head = [3,2,0,-4], pos = 1
// Output: true
// 3 → 2 → 0 → -4
//     ↑       ↓
//     └───────┘



// 142 Linked List Cycle II                    TC O(n) and SC O(1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* point = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                while (slow != point) {
                    point = point->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};
// Input: head = [3,2,0,-4], pos = 1
// Output: tail connects to node index 1
// 3 → 2 → 0 → -4
//     ↑       ↓
//     └───────┘
// Explanation: There is a cycle in the linked list, where tail connects to the second node. So return the second node.