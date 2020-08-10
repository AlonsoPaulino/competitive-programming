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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *prev = NULL, *end = head;
        for (int i = 1; i < n; ++i) end = end->next;
        while (end->next != NULL) {
            prev = (prev == NULL ? head : prev->next);
            end = end->next;
        }
        if (prev == NULL) return head->next;
        else prev->next = prev->next->next;
        return head;
    }
};