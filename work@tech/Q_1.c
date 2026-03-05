Given a linked list, remove the loop if it exists. 
You need to find the last node of the list that points to one of its previous nodes and make it point to NULL.
/* This is the ListNode struct definition

struct ListNode {

	int data;
	struct ListNode* next;
};
*/

void removeLoop(struct ListNode* list) 
{
    struct ListNode *slow = list, *fast = list;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            slow = list;

            if (slow == fast)
            {
                while (fast->next != slow)
                    fast = fast->next;
            }
            else
            {
                while (slow->next != fast->next)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
            }

            fast->next = NULL;
            return;
        }
    }
    // add your logic here
}
