#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* reverseBetween(ListNode* head, int B, int C);
    ListNode* make_list(vector<int> nums);
};

pair<ListNode*, ListNode*> reverse(ListNode* from, ListNode* to) {
    ListNode *prev = nullptr, *curr = from->next, *next = curr->next, *toNext = to->next;

    while (curr != toNext) {
        curr->next = prev;
        prev = curr;
        curr = next;
        next = curr != nullptr ? curr->next : nullptr;
    }

    return {prev, curr};
}

ListNode* Solution::reverseBetween(ListNode* head, int B, int C) {
    if (B == C) return head;

    ListNode* dummy = new ListNode(0, head);

    ListNode *from = dummy, *to = head;

    while (from->next->val != B) {
        from = from->next;
    }

    ListNode* fromNext = from->next;

    while (to->val != C) {
        to = to->next;
    }

    pair<ListNode*, ListNode*> nodes = reverse(from, to);

    from->next = nodes.first;
    fromNext->next = nodes.second;

    if (fromNext->val == head->val) head = nodes.first;

    return head;
}

ListNode* Solution::make_list(vector<int> nums) {
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
    Solution sol;
    ListNode* head = sol.make_list(nums);
    ListNode* newHead = sol.reverseBetween(head, 1, 5);

    int i = 0;

    while (newHead != NULL) {
        cout << newHead->val << " -> ";
        newHead = newHead->next;
        i++;
    }

    return 0;
}