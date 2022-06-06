// 160. Intersection of Two Linked Lists:  https://leetcode.com/problems/intersection-of-two-linked-lists
// Tags: #link-list #easy
// Efficiency: Time Complexity O(n+m), Space Complexity O(1)
#include<iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode* next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pointerA = headA, *pointerB = headB;
        
        while(pointerA != pointerB){
            pointerA = pointerA ? pointerA->next : headB;
            pointerB = pointerB ? pointerB->next : headA;
        }
        
        return pointerA;
    }
};
