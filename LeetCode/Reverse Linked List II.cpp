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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        
        ListNode *front = NULL;
        ListNode *a = head;
        
        for (int i = 1; i < left; ++i) {
            front = a, a = a->next;
        }
        if (front != NULL) front->next = NULL;
        
        ListNode *back = NULL;
        ListNode *b = NULL;
        
        ListNode *prev = a;
        back = prev->next;
        prev->next = NULL;
        
        for (int i = left + 1; i <= right; ++i) {
            b = back, back = b->next;
            b->next = prev;
            prev = b;
        }
        
        a->next = back;
        if (front != NULL) {
            front->next = b;
        } else {
            return b;
        }
        
        return head;
    }
};
