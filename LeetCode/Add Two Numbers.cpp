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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode * rem = NULL, * hans = NULL, * ans = NULL;
        while (l1 != NULL && l2 != NULL) {
            int x = l1->val, y = l2->val;
            ListNode *d = new ListNode((x + y + carry) % 10);
            if (hans == NULL) hans = d, ans = hans; else ans->next = d, ans = ans->next;
            carry = x + y + carry > 9 ? 1 : 0;
            l1 = l1->next, l2 = l2->next;
        }
        if (l1 != NULL) rem = l1;
        else if (l2 != NULL) rem = l2;
        while (rem != NULL) {
            ListNode *d = new ListNode((rem->val + carry) % 10);
            if (hans == NULL) hans = d, ans = hans; else ans->next = d, ans = ans->next;
            carry = rem->val + carry > 9 ? 1 : 0;
            rem = rem->next, d = d->next;
        }
        if (carry > 0) {
            ans->next = new ListNode(carry);
        }
        return hans;
    }
};