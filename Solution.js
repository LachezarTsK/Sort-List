
/**
 * @param {number} val
 * @param {ListNode}next
 */
function ListNode(val, next) {
    this.val = (val === undefined ? 0 : val);
    this.next = (next === undefined ? null : next);
}

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var sortList = function (head) {
    if (head === null || head.next === null) {
        return head;
    }
    
    let middleNode = iterateToMiddleNode(head);
    let list1 = sortList(head);
    let list2 = sortList(middleNode);
    
    return merge(list1, list2);
};

/**
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */
function merge(list1, list2) {

    let sentinel = new ListNode();
    let current = sentinel;

    while (list1 !== null && list2 !== null) {
        if (list1.val < list2.val) {
            current.next = list1;
            list1 = list1.next;
        } else {
            current.next = list2;
            list2 = list2.next;
        }
        current = current.next;
    }
    
    current.next = (list1 !== null) ? list1 : list2;
    return sentinel.next;
}

/**
 * @param {ListNode} node
 * @return {ListNode}
 */
function iterateToMiddleNode(node) {
    let temp = null;
    while (node !== null && node.next !== null) {
        temp = (temp === null) ? node : temp.next;
        node = node.next.next;
    }
    
    let middle = temp.next;
    temp.next = null;
    return middle;
}
