
// Struct ListNode is in-built in the solution file on leetcode.com. 
// When running the code on the website, do not include this struct.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:

    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* middleNode = iterateToMiddleNode(head);
        ListNode* list1 = sortList(head);
        ListNode* list2 = sortList(middleNode);

        return merge(list1, list2);
    }

    ListNode* merge(ListNode* list1, ListNode* list2) {

        ListNode* sentinel = new ListNode();
        ListNode* current = sentinel;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        current->next = (list1 != nullptr) ? list1 : list2;
        current = nullptr;
        delete current;

        return sentinel->next;
    }

    ListNode* iterateToMiddleNode(ListNode* node) {

        ListNode* temp = nullptr;
        while (node != nullptr && node->next != nullptr) {
            temp = (temp == nullptr) ? node : temp->next;
            node = node->next->next;
        }

        ListNode* middle = temp->next;
        temp->next = nullptr;
        delete temp->next;

        return middle;
    }
};
