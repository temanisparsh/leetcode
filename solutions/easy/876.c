
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *middleNode(struct ListNode *head)
{
    int n = 0;
    struct ListNode* curr = head;

    while(curr) {
        curr = curr->next;
        ++n;
    }
    curr = head;
    for(int i = 0;  i < n/2; ++i)
        curr = curr->next;
    return curr;
}