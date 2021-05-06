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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<int> v;
    int n;
public:
    TreeNode* solve(int i, int j) {
        if (i > j) return NULL;
        int mid = i + (j - i) / 2;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = solve(i, mid - 1);
        root->right = solve(mid + 1, j);
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        while (head != NULL) {
            v.push_back(head->val);
            head = head->next;
        }
        n = (int) v.size();
        if (n == 0) return NULL;
        
        TreeNode* root = solve(0, n - 1);
        return root;
    }
};
