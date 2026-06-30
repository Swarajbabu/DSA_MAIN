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


// 19 Remove Nth Node From End of List          BRUTE FORCE SOLUTION  O(n) TC and O(n) SC
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


// 19 Remove Nth Node From End of List          OPTIMAL SOLUTION  O(n) TC and O(1) SC
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
        ListNode* dimmy = new ListNode(0);
        dimmy->next = head;

        ListNode* slow = dimmy;
        ListNode* fast = dimmy;

        for(int i=0;i<n;i++){
            fast = fast->next;
        }
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* delnode = slow->next;
        slow->next = slow -> next -> next;
        delete delnode;
        return dimmy->next;
    }
};
// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]
// explanation: Given n will always be valid. 1 ≤ n ≤ sz, where sz is the size of the linked list.


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


// 328 Odd Even Linked List                 TC O(n) and SC O(1)
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = head;
        ListNode* even = head->next;
        
        ListNode* evenHead = even;
        while(even != NULL && even->next != NULL){
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd ->next = evenHead;
        return head;
    }
};
// Input: head = [1,2,3,4,5]
// Output: [1,3,5,2,4]
// Explanation: The first node is the odd node, the second node is the even node, and so on ... Note that the relative order inside both the even and odd groups should remain as it was in the input. The first node of the even group (node 2) should follow the last node of the odd group (node 5).


// 234 Palindrome Linked List                 TC O(n) and SC O(1)
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
ListNode* reversell(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next){
            slow = slow -> next;
            fast = fast ->next->next;
        }

        // If the list has an odd number of elements, move slow one step further to skip the middle element
        if(fast!=NULL){
            slow = slow->next;
        }
        ListNode* secondHalf = reversell(slow);
        
        ListNode* FirstHalf = head;
        ListNode* temp = secondHalf;

        while(temp != NULL){
            if (FirstHalf->val != temp->val) {
                return false;
            }
            temp = temp->next;
            FirstHalf = FirstHalf->next;
        }
        return true;
    }
};
// Input: head = [1,2,2,1]
// Output: true

// Input: head = [1,2]
// Output: false
// Explanation: The first node is the odd node, the second node is the even node, and so on ... Note that the relative order inside both the even and odd groups should remain as it was in the input. The first node of the even group (node 2) should follow the last node of the odd group (node 5).



// 92 Reverse Linked List II                 TC O(n) and SC O(1)
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
ListNode* reversell(ListNode* temp, int cnt) {
    ListNode* prev = NULL;
    ListNode* curr = temp;
    ListNode* next = NULL;

    while(curr != NULL && cnt != 0){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt--;
    }
    return prev;
}
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left==right){
            return head;
        }

        ListNode* dimmy = new ListNode(0);
        dimmy->next = head;

        ListNode* prev = dimmy;
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* start = prev->next;
        ListNode* endnext = start;

        int cnt = right - left + 1;

        for(int i=0;i<cnt;i++){
            endnext = endnext->next;
        }
        ListNode* reverse = reversell(start, cnt);
        prev->next = reverse;
        start->next = endnext;
        
        return dimmy->next;
    }
};
// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]
// Explanation: Reverse the nodes from position 2 to 4. The first node is the odd node, the second node is the even node, and so on ... Note that the relative order inside both the even and odd groups should remain as it was in the input. The first node of the even group (node 2) should follow the last node of the odd group (node 5).



// 2130 Maximum Twin Sum of a Linked List                 TC O(n) and SC O(1)
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
ListNode* reverseLL(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;

    while (curr) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* reverse = reverseLL(slow);
        
        ListNode* firsthalf = head;
        ListNode* secondhalf = reverse;
        int max_pair = 0;
        while(secondhalf != NULL && firsthalf != NULL){
            int sum = secondhalf->val + firsthalf->val;
            max_pair = max(max_pair,sum);
            secondhalf = secondhalf->next;
            firsthalf = firsthalf->next;
        }
        return max_pair;
    }
};
// Input: head = [5,4,2,1]
// Output: 6
// nth node from the start is 5, and the nth node from the end is 1. The twin sum is 5 + 1 = 6. The maximum twin sum is 6.
// Explanation: The maximum twin sum is 6. The nodes forming the twin sum are 5 and 1, which are at positions 1 and 4 respectively.

