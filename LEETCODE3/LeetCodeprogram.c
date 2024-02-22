int GetTheSize(struct ListNode* head){
    struct ListNode* temp = head;
    int i = 0;
    while(temp != NULL){
        temp = temp->next;
        i++;
    }
    return i;
}

struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize) {
    struct ListNode *current = head, *next = NULL;
    int n = GetTheSize(head);

    *returnSize = k;

    struct ListNode** array = malloc(sizeof(struct ListNode*) * (*returnSize));

    int parts = n / k;
    int overStay = n%k;




    for(int i = 0; i < k; i++){
        array[i] = head;

        int currentPartSize = parts + (overStay-- > 0 ? 1 : 0);

        for(int j = 1; j < currentPartSize && head != NULL; j++){
            head = head->next;
        }
        if(head != NULL){
            next = head->next;
            head->next = NULL;
            head = next;
        }
    }
    return array;
}
