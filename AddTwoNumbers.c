/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if(l1->next == NULL && l2->next == NULL){
        struct ListNode *res = malloc(sizeof(struct ListNode));
        res->val = l1->val + l2->val;
        res->next = NULL;
        return res; 
    }

    struct ListNode *cur = malloc(sizeof(struct ListNode));
    struct ListNode *head = cur;
    while(l1 != NULL){
        //struct ListNode *tmp;
        cur->val = l1 -> val;
        if(l1->next == NULL){
            l1 = NULL;
            cur->next = NULL;
            continue;
        }
        printf("%d\n", cur->val);
        l1 = l1->next;
        cur->next = malloc(sizeof(struct ListNode));
        cur = cur->next;  
    }
    printf("%d please", cur->val);
    struct ListNode *tmp2 = malloc(sizeof(struct ListNode));
    tmp2-> val = l2-> val;
    tmp2->next = l2->next;
    struct ListNode *cur2 = head;
    int carry = 0;
    //int tocar = 0;
    while(tmp2 != NULL){
        
        printf("cur2 val is %d\n", cur2 -> val);
        int res = cur2->val + tmp2->val;
        if(carry ==1 && tmp2->val == 0){
            tmp2->val = 1 + cur2->val;

            continue;
        }
        if(carry ==1){
            res = res +1;
            carry = 0;
        }
        if(res >= 10 ){
            res = res - 10;
            carry = 1; 
        }
        cur2->val = res;
        printf("tmp2 val %d\n", tmp2->val);
        printf("This is sum %d\n", cur2->val);
        /*
        if(tmp2->next == NULL && cur2->next != NULL){
            tmp2->next = malloc(sizeof(struct ListNode));
            tmp2=tmp2->next;
            tmp2->val = 0;
        }
        */
        if(tmp2->next == NULL){
            tmp2 = NULL;
            cur2->next = NULL;
            continue;
        }

        tmp2 = tmp2->next;
       
        cur2 = cur2->next;
    }

    return head;
    

    //printf("%d", cur->val);
   // printf("%d", res->val);
    
}
