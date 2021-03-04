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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ita = headA, *itb = headB;
        int a = 0, b = 0;
        while (ita != NULL) ita = ita->next, ++a;
        while (itb != NULL) itb = itb->next, ++b;
        if (b > a) {
            ita = headB, itb = headA;
            swap(a, b);
        } else {
            ita = headA, itb = headB;
        }
        for (int i = 0; i < a - b; ++i) ita = ita->next;
        while (ita != NULL && itb != NULL) {
            if (ita == itb) return ita;
            ita = ita->next, itb = itb->next;
        }
        return NULL;
    }
};
