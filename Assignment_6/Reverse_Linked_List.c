/*
 * Problem : Reverse Linked List in given range.
 * Raghav 1910990074 21/08/21
 * Assignment_6 -> Linked List
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
        
    if(head == NULL) return NULL;
    
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0;
	dummy->next = head;
    
    struct ListNode* pre = dummy; 
    
    for(int i = 0; i<left-1; i++) pre = pre->next;
    
    struct ListNode* slow = pre->next; 
    struct ListNode* fast = slow->next; 
    
    
    for(int i=0; i<right-left; i++)
    {
        slow->next = fast->next;
        fast->next = pre->next;
        pre->next = fast;
        fast = slow->next;
    }
    
    return dummy->next;
}