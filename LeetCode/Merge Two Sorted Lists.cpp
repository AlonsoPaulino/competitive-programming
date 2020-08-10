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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(), *i = head;
        while (l1 != NULL || l2 != NULL) {
            if (l1 == NULL) i->next = new ListNode(l2->val), l2 = l2->next;
            else if (l2 == NULL) i->next = new ListNode(l1->val), l1 = l1->next;
            else if (l1->val > l2->val) i->next = new ListNode(l2->val), l2 = l2->next;
            else i->next = new ListNode(l1->val), l1 = l1->next;
            i = i->next;
        }
        return head->next;
    }
};