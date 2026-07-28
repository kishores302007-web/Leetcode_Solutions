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
#include <algorithm>
#include <utility>

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        unsigned long long maxWidth = 0;
        
        // Queue tracks pairs of: {Node pointer, Node position index}
        std::queue<std::pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int levelSize = q.size();
        
            unsigned long long minLevelIndex = q.front().second; 
            unsigned long long first = 0, last = 0;

            for (int i = 0; i < levelSize; ++i) {
                unsigned long long currentNormalizedIndex = q.front().second - minLevelIndex;
                TreeNode* node = q.front().first;
                q.pop();
                if (i == 0) {
                    first = currentNormalizedIndex;
                }
                if (i == levelSize - 1) {
                    last = currentNormalizedIndex;
                }
                if (node->left != nullptr) {
                    q.push({node->left, 2 * currentNormalizedIndex});
                }
                if (node->right != nullptr) {
                    q.push({node->right, 2 * currentNormalizedIndex + 1});
                }
            }
            maxWidth = std::max(maxWidth, last - first + 1);
        }

        return static_cast<int>(maxWidth);
    }
};
