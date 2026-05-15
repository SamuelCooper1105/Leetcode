/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    //special case where there is only one element in both lists, check if next for both lists is NULL
    //if both next members are set to NULL then we need to just return the sum of the elements without going through rest of the code
    if(l1->next == NULL && l2->next == NULL){
        struct ListNode *res = malloc(sizeof(struct ListNode));
        res->val = l1->val + l2->val;
        res->next = NULL;
        return res; 
    }
    //we need a node to iterate through the list and save our values. This is cur.
    //also need a node to save the head of the saved linked list. since it's pointing to the same memory space it can access the members of the cur list.
    struct ListNode *cur = malloc(sizeof(struct ListNode));
    struct ListNode *head = cur;
    while(l1 != NULL){
        cur->val = l1 -> val;
        //copy values 
        if(l1->next == NULL){
            l1 = NULL;
            cur->next = NULL;
            continue;
        }
        //checks if l1 next is null if it is then we need to stop the loop so we just continue and set l1 to null so the loop stops.
        l1 = l1->next;
        cur->next = malloc(sizeof(struct ListNode));
        cur = cur->next;  
        // Print the value so we know if its right, just for debugging
        // set l1 to l1-> next 
        //cur isn't properly initlized so we need to allocate some memory and set cur to next, this means its empty
        //prior if check sets next to null if there isn't another node. 
    }
    printf("%d please\n", cur->val);
    cur = head;
    int carry = 0;
    //reset cur to head position. we also need a carry flag when adding the numbers
    while(l2 != NULL){
        printf("cur val is %d\n", cur -> val);
     /*   if(cur->next == NULL && l2->next == NULL && carry ==1){
            cur->next = malloc(sizeof(struct ListNode));
            cur->next->next = NULL;
            cur->next->val =1;
            continue;
        }
        */
        if(cur->next == NULL && l2->next != NULL){
            cur->next = malloc(sizeof(struct ListNode));
            cur->next->val = 0;
        }
        
        else if ( cur->next != NULL && l2 -> next == NULL){
            l2->next = malloc(sizeof(struct ListNode));
            l2->next->val = 0;
            l2->next->next = NULL;
            if(carry == 1){
                cur->val ++;
                if(cur->val >= 10){
                    cur->val = cur->val -10;
                    carry = 1;
                    continue;
                }
                carry = 0;
                continue;   
            }
        }    
        int res = cur->val + l2->val;
        if(carry ==1){
            res = res +1;
            carry = 0;
        }
        if(res >= 10 ){
            res = res - 10;
            carry = 1; 
        }
        cur->val = res;
        l2 = l2-> next;
        cur = cur->next;
    }

    return head; 
}
