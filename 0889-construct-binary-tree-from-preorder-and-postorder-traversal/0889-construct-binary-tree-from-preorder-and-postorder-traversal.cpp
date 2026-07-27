class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        stack<TreeNode*> st;
        
        TreeNode* root = new TreeNode(preorder[0]);
        st.push(root);
        
        int postIdx = 0;
        
        for (int i = 1; i < preorder.size(); ++i) {
            TreeNode* node = new TreeNode(preorder[i]);
            
            while (st.top()->val == postorder[postIdx]) {
                st.pop();
                postIdx++;
            }
            
            if (st.top()->left == nullptr) {
                st.top()->left = node;
            } else {
                st.top()->right = node;
            }
            
            st.push(node);
        }
        
        return root;
    }
};
