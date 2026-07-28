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
#include <queue>

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        std::queue<TreeNode*> q;
        q.push(root);
        
        bool seenNull = false;

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if (current == nullptr) {
                seenNull = true;
            } else {
                if (seenNull) {
                    return false;
                }
                q.push(current->left);
                q.push(current->right);
            }
        }

        return true;
    }
};
