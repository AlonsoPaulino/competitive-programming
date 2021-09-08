/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;
        
        ListNode* x = NULL;
        ListNode* y = head;
        
        while (y != NULL) {
            ListNode* tmp = y->next;
            y->next = x;
            x = y;
            y = tmp;
        }
        
        return x;
    }
};

// Another solution written at 01/28/2021
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;
        
        ListNode *a = head, *b = head->next;
        a->next = NULL;
        while (b != NULL) {
            ListNode *tmp = b->next;
            b->next = a;
            a = b, b = tmp;
        }
        return a;
    }
};

// Another solution written on 09/08/2021
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL; ListNode* curr = head;
        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr, curr = next;
        }
        return prev;
    }
};
