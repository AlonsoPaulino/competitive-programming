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