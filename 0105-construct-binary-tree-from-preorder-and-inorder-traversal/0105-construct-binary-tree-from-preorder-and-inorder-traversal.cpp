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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> st;
        st.push(root);

        int inorderIndex = 0;

        for (int i = 1; i < preorder.size(); ++i) {
            int currVal = preorder[i];
            TreeNode* currNode = st.top();
            if (currNode->val != inorder[inorderIndex]) {
                currNode->left = new TreeNode(currVal);
                st.push(currNode->left);
            } 
            else {
                while (!st.empty() && st.top()->val == inorder[inorderIndex]) {
                    currNode = st.top();
                    st.pop();
                    inorderIndex++;
                }
                currNode->right = new TreeNode(currVal);
                st.push(currNode->right);
            }
        }

        return root;
    }
};