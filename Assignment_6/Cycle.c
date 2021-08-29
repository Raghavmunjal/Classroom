/*
 * Problem : Return the node from where cycle begins, if cycle exists, in the singly linked list.
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
struct ListNode *detectCycle(struct ListNode *head) {
    
        struct ListNode *slow = head;
        struct ListNode *fast = head;
        int flag = 1;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                flag = 0;
                break;
            }
        }
    
        if(flag == 1){
            return NULL;
        }
        slow = head;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
}