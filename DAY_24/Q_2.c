203. Remove Linked List Elements
struct ListNode* removeElements(struct ListNode* head, int val) {
    while (head != NULL && head->val == val) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
    
    struct ListNode* current = head;
    struct ListNode* prev = NULL;
    
    while (current != NULL) {
        if (current->val == val) {
            prev->next = current->next;
            free(current);
            current = prev->next;
        } else {
            prev = current;
            current = current->next;
        }
    }
    
    return head;
}
