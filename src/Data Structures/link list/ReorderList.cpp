#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *next;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

void reorderList(ListNode *head)
{
    ListNode *rightPointer = head;
    ListNode *leftPointer = head;

    while (rightPointer->next != NULL)
    {
        rightPointer = rightPointer->next->next != NULL ? rightPointer->next->next : rightPointer->next;
        leftPointer = leftPointer->next;
    }

    rightPointer = leftPointer->next;
    leftPointer->next = NULL;
    leftPointer = head;
    rightPointer = reverseList(rightPointer);

    ListNode *next1;
    ListNode *next2;

    while (leftPointer->next != NULL && rightPointer != NULL)
    {
        next1 = leftPointer->next;
        next2 = rightPointer->next;

        leftPointer->next = rightPointer;
        rightPointer->next = next1;

        rightPointer = next2;
        leftPointer = next1;
    }
}

int main()
{
    ListNode l1(3, NULL);
    ListNode l2(6, &l1);
    ListNode l3(9, &l2);

    ListNode *temp = &l3;
    int i = 0;

    temp = reverseList(&l3);

    while (temp != NULL && i != 5)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
        i++;
    }
}