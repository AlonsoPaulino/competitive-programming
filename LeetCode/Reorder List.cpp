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
    void reorderList(ListNode* head) {
        if (!head) return;
        ListNode *x = head, *prev = head, *y = head->next;
        while (x->next && y->next) {
            while (y && y->next) prev = prev->next, y = y->next;
            prev->next = NULL;
            y->next = x->next;
            x->next = y;
            x = y->next;
            prev = x, y = x->next;
        }
    }
};