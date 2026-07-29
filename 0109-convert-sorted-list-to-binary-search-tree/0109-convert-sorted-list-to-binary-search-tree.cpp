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
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int length = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            length++;
            curr = curr->next;
        }
        return convertListToBST(head, 0, length - 1);
    }
    TreeNode* convertListToBST(ListNode*& head, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        
        int mid = start + (end - start) / 2;
        TreeNode* leftChild = convertListToBST(head, start, mid - 1);
        TreeNode* root = new TreeNode(head->val);
        root->left = leftChild;
        head = head->next;
        root->right = convertListToBST(head, mid + 1, end);
        
        return root;
    }
};
