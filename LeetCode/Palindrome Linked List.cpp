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
    bool isPalindrome(ListNode* head) {
        if (head == NULL) return false;
        if (head->next == NULL) return true;
        
        ListNode* a = head;
        ListNode* b = head->next;
        
        while (a != NULL && b != NULL && b->next != NULL) {
            a = a->next;
            b = b->next->next;
        }
        
        b = a->next;
        a->next = NULL;
        
        ListNode* x = b->next;
        b->next = NULL;
        
        while (x != NULL) {
            ListNode* tmp = x->next;
            x->next = b;
            b = x, x = tmp;
        }
        
        a = head;
        
        while (a != NULL && b != NULL) {
            if (a->val != b->val) return false;
            a = a->next, b = b->next;
        }
        
        return true;
    }
};
