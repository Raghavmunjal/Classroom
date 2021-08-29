/*
 * Problem : Merge Two Sorted Linked Lists
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

int length(struct ListNode* l){
        struct ListNode* temp = l;
        int count = 0;
        while(l!=NULL){
            count++;
            l = l->next;
        }
        return count;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
        int n = length(l1);
        int m = length(l2);
        
        int i = 0;
        int j = 0;

        struct ListNode* result = (struct ListNode*)malloc(sizeof(struct ListNode));
        result->val = -1;
        result->next = NULL;
    
        struct ListNode* res = result;
    
        while(i<n && j<m){
            
            if(l1->val <= l2->val){
               res->next = l1;
               res = res->next;
               l1 = l1->next;
               i++;
            }else{
                res->next = l2;
                res = res->next;
                l2 = l2->next;
                j++;
            }
            
        }
        
        while(i<n){
            res->next = l1;
            i++;
            l1 = l1->next;
            res = res->next;
        }
        while(j<m){
            res->next = l2;
            j++;
            l2 = l2->next;
            res = res->next;
        }
        return result->next;
}