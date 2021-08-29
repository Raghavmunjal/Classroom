/*
 * Problem : Rotate Linked List.
 * Raghav 1910990074 25/08/21
 * Assignment_6 -> Linked List
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
            
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    if(head == NULL)
        return NULL;
    
    else if(head->next == NULL)
        return head;

    for(int i = 1; i <= k; i++){
        
        fast = fast->next;
        if(fast == NULL){
            fast = head;
            k = k % i;
            i = 0;
        }

    }
    
    if(slow == fast)
        return head;

    while(fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;

    }

    struct ListNode *ans = slow->next;
    slow->next = NULL;
    fast->next = head;

    return ans;
    
}