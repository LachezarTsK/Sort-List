
public class Solution {

    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        
        ListNode middleNode = iterateToMiddleNode(head);
        ListNode list1 = sortList(head);
        ListNode list2 = sortList(middleNode);
        
        return merge(list1, list2);
    }

    public ListNode merge(ListNode list1, ListNode list2) {

        ListNode sentinel = new ListNode();
        ListNode current = sentinel;

        while (list1 != null && list2 != null) {
            if (list1.val < list2.val) {
                current.next = list1;
                list1 = list1.next;
            } else {
                current.next = list2;
                list2 = list2.next;
            }
            current = current.next;
        }
        
        current.next = (list1 != null) ? list1 : list2;
        return sentinel.next;
    }

    public ListNode iterateToMiddleNode(ListNode node) {
        ListNode temp = null;
        while (node != null && node.next != null) {
            temp = (temp == null) ? node : temp.next;
            node = node.next.next;
        }
        
        ListNode middle = temp.next;
        temp.next = null;
        return middle;
    }
}

// Class ListNode is in-built in the solution file on leetcode.com. 
// When running the code on the website, do not include the class.
class ListNode {

    int val;
    ListNode next;

    ListNode() {}

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}
