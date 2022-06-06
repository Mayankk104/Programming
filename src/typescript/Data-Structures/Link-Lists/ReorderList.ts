// leetcode: 143. Reorder List https://leetcode.com/problems/reorder-list/ #Blind_75

class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val === undefined ? 0 : val)
        this.next = (next === undefined ? null : next)
    }
}

function reorderList(head: ListNode | null): void {
    let fastPointer = head, slowPointer = head;

    while (fastPointer.next) {
        fastPointer = fastPointer.next.next ? fastPointer.next.next : fastPointer.next;
        slowPointer = slowPointer.next;
    }

    fastPointer = slowPointer.next;
    fastPointer = reverseList(fastPointer);
    slowPointer.next = null;
    let temp = head;

    while (temp !== slowPointer && fastPointer) {
        let next1 = temp.next;
        let next2 = fastPointer.next;

        temp.next = fastPointer
        fastPointer.next = next1;

        fastPointer = next2;
        temp = next1;
    }

};

function reverseList(head: ListNode): ListNode {
    let prev = null, curr = head, next;

    while (curr) {
        next = curr.next;
        curr.next = prev;
        prev = curr
        curr = next;
    }
    return prev;
}