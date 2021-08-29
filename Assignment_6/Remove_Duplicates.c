/*
 * Problem : Remove Duplicates from Sorted Linked List.
 * Raghav 1910990074 27/08/21
 * Assignment_6 -> Linked List
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteDuplicates(struct ListNode* head){
    

    if(head == NULL || head->next == NULL)
        return head;
    
    struct ListNode *curr = head->next;
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = -1;
	dummy->next = NULL;
    struct ListNode *prev = dummy;
    prev->next = head;
    while(curr!=NULL){
        bool flag = false;
        while(curr!=NULL && prev->next->val == curr->val){
            flag = true;
            curr = curr->next;
        }
        if(flag)
            prev->next = curr;
        else
            prev = prev->next;
            
        if(curr!=NULL)
            curr = curr->next;
    }
    
    return dummy->next;

}