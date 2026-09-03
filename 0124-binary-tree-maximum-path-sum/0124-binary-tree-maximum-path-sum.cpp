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

    int ans = INT_MIN;

    int dfs(TreeNode* root) {

        if (root == nullptr)
            return 0;

        // Best contribution from left and right
        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));

        // Complete path passing through current node
        int currentPath = left + root->val + right;

        // Update global answer
        ans = max(ans, currentPath);

        // Return only ONE branch to parent
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {

        dfs(root);

        return ans;
    }
};