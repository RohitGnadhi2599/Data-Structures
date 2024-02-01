/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct ListNode lnode;
int get_len(lnode *head)
{
    int n = 0;
    while(head)
    {
        n++;
        head = head->next;
    }
    return n;
}
struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize)
{
    int n = get_len(head), elems, i, j;
    *returnSize = k;
    lnode **list = (lnode**)calloc(k, sizeof(lnode*)), *t = head;
    if(n>k)
    {
        for(i=0;i<k;i++)
        {
            elems = i<n%k?n/k+1:n/k;
            j=0;
            list[i] = head;
            t = head;
            while(j++<elems)
            {
                t = head;
                head = head->next;
            }
            t->next = NULL;
        }
    }
    else
    {
        for(i=0;i<n;i++)
        {
            list[i] = head;
            head = head->next;
            list[i]->next = NULL;
        }
    }
    return list;
}
