/*
 * Problem : Linked List is Pallindrome or not
 * Raghav 1910990074 24/08/21
 * Assignment_6 -> Linked List
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */



struct ListNode * reverse(struct ListNode * head){
    struct ListNode * next = NULL, * prev = NULL;
    
    while (head != NULL){
        next = head -> next;
        head -> next = prev;
        
        prev = head;
        head = next;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head){
    struct ListNode * slow = head, *fast = head;
    while (fast -> next != NULL && fast -> next -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    
    slow = reverse(slow);
    
    fast = head;
    
    while (fast != NULL && slow != NULL){
        if (fast -> val != slow -> val){
            return false;
        }
        fast = fast -> next;
        slow = slow -> next;
    }
    
    return true;
    
}