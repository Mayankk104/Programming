
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
   public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return NULL;

        ListNode *fast = head->next->next;
        ListNode *slow = head->next;

        while (fast != slow) {
            fast = (fast->next != NULL && fast->next->next) ? fast->next->next : fast->next;
            slow = slow->next;

            if (fast == NULL || fast->next == NULL)
                return NULL;
        }

        slow = head;

        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};