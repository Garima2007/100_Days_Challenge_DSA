876. Middle of the Linked List
Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.
  struct ListNode* middleNode(struct ListNode* head) 
{
struct ListNode *t = head;
struct ListNode *p = head;
while(t != NULL && t->next != NULL)
{
    p = p ->next;
    t = t->next->next;
}
return p;
}
