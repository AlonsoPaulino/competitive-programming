/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* ans = head;
        ListNode* x = head->next;
        while (x != NULL) {
            ans = ans->next;
            x = x->next;
            if (x != NULL) x = x->next;
        }
        return ans;
    }
};