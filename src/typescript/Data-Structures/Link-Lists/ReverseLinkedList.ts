// leetcode: 206. Reverse Linked List https://leetcode.com/problems/reverse-linked-list/ 
// Tags: #Blind_75
// Efficiency: Time Complexity O(n), Space Complexity O(1)

class ListNode {
    constructor(
        private val: number = 0,
        public next: ListNode | null = null
    ) { }
}

function reverseList(head: ListNode | null): ListNode | null {
    let previous: ListNode | null = null;
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