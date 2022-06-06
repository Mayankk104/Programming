// leetcode: 21. Merge Two Sorted Lists  https://leetcode.com/problems/merge-two-sorted-lists/
// #Blind_75

class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val === undefined ? 0 : val)
        this.next = (next === undefined ? null : next)
    }
}


function mergeTwoLists(list1: ListNode | null, list2: ListNode | null): ListNode | null {
    if (!list1 && list2)
        return list2;
    if ((!list2 && list1) || (!list1 && !list2))
        return list1;

    let curr1 = list1, next1;
    let curr2 = list2, next2;

    while (curr1 && curr2) {
        if (curr1.val > curr2.val) {
            while (curr2.next && curr2.next.val <= curr1.val)
                curr2 = curr2.next

            next2 = curr2.next;
            curr2.next = curr1;
            curr2 = next2;

        } else {
            while (curr1.next && curr1.next.val <= curr2.val)
                curr1 = curr1.next

            next1 = curr1.next;
            curr1.next = curr2;
            curr1 = next1;
        }
    }

    if (list1.val <= list2.val)
        return list1;
    else
        return list2;
};