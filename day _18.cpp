class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty())
            return NULL;

        TreeNode* root = new TreeNode(preorder[0]);

        int index = 0;
        while (inorder[index] != preorder[0])
            index++;

        vector<int> leftPreorder(preorder.begin() + 1,
                                 preorder.begin() + index + 1);

        vector<int> leftInorder(inorder.begin(),
                                inorder.begin() + index);

        root->left = buildTree(leftPreorder, leftInorder);

        vector<int> rightPreorder(preorder.begin() + index + 1,
                                  preorder.end());

        vector<int> rightInorder(inorder.begin() + index + 1,
                                 inorder.end());

        root->right = buildTree(rightPreorder, rightInorder);

        return root;
    }
};
