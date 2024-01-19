/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//Reverse the linked list from node head, and link it with other
//nodes which came from the original one's tail
struct ListNode* inde(struct ListNode* head,int index)
{
    int i=0;
    while(i<index-1)
    {
        head =head -> next ;
        i++;
    }
    return head;
}

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    int temp;
    struct ListNode *copy,*l,*r;
    copy=head;
    while(left<right)
    {
        l=inde(head,left);
        r=inde(head,right);
        temp=l->val;
        l->val=r->val;
        r->val=temp;
        left++;
        right--;
    }
    return head;


}