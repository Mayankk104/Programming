// leetcode: 206. Reverse Linked List https://leetcode.com/problems/reverse-linked-list/ #Blind_75

/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function reverseList(head: ListNode | null): ListNode | null {
    let previous = null
    let current = head;
    let next;

    while (current !== null) {
        next = current.next;
        current.next = previous;
        previous = current;
        current = next;
    }
    return previous;
};