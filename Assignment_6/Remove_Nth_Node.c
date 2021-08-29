/*
 * Problem : Remove Nth node from end
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


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    
        int size=0;
        struct ListNode *curr = head;
        while(curr!=NULL){
            size++;
            curr = curr->next;
        }
        struct ListNode *slow=head;
        struct ListNode *fast=head;
        
        if(n > size)
            return NULL;
        
        if(n == size)
            return head->next;
        
        for(int i=0;i<n;i++){
            if(fast == NULL)return NULL;
            fast = fast->next;
        }
        
        struct ListNode *prev=NULL;
        while(fast!=NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        prev->next = slow->next;
        return head;
}