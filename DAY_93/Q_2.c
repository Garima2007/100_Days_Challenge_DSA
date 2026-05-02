/*
147. Insertion Sort List
Constraints:

The number of nodes in the list is in the range [1, 5000].
-5000 <= Node.val <= 5000
*/
struct ListNode* insertionSortList(struct ListNode* head) {
    if (!head || !head->next) return head;

    struct ListNode dummy;
    dummy.next = NULL;

    struct ListNode* curr = head;

    while (curr) {
        struct ListNode* next = curr->next;

        // find position in sorted list
        struct ListNode* prev = &dummy;
        while (prev->next && prev->next->val < curr->val) {
            prev = prev->next;
        }

        // insert current node
        curr->next = prev->next;
        prev->next = curr;

        curr = next;
    }

    return dummy.next;
}
