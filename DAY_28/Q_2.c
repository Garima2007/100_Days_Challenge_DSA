234. Palindrome Linked List
struct ListNode* reverse(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return true;

    struct ListNode *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    slow = reverse(slow);

    struct ListNode* first = head;
    struct ListNode* second = slow;

    while (second != NULL) {
        if (first->val != second->val)
            return false;
        first = first->next;
        second = second->next;
    }

    return true;
}
