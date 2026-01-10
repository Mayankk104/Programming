#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode *prev = nullptr, *curr = head, *next = curr->next;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

ListNode* recursion(ListNode* curr_head, int k) {
    if (curr_head == nullptr) return nullptr;
    ListNode* to = curr_head;
    int x = 1;

    while (to->next != nullptr && x < k) {
        to = to->next;
        x++;
    }

    ListNode* nexHead = to->next;
    to->next = nullptr;
    ListNode* prev = reverseList(curr_head);
    ListNode* temp = recursion(nexHead, k);
    curr_head->next = temp;
    return prev;
}

ListNode* reverse_group_of_k(ListNode* head, int k) {
    return recursion(head, k);
}

ListNode* make_list(vector<int> nums) {
    ListNode* head = new ListNode(nums[0]);
    ListNode* temp = head;

    for (int i = 1; i < nums.size(); i++) {
        temp->next = new ListNode(nums[i]);
        temp = temp->next;
    }

    return head;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    ListNode* head = make_list(nums);
    int i = 0;

    ListNode* temp = reverse_group_of_k(head, 2);

    while (temp != NULL) {
        cout << temp->val << " -> ";
        temp = temp->next;
        i++;
    }
}