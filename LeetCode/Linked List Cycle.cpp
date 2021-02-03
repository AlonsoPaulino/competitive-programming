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
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        
        ListNode *a = head, *b = head->next;
        
        while (b != NULL && b->next != NULL) {
            if (a == b) {
                return true;
            }
            a = a->next;
            b = b->next->next;
        }
        
        return false;
    }
};
