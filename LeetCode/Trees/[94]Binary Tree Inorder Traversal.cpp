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
    void createInorderList(vector<int> &inorderList, TreeNode* root) {
        if (root == NULL)
            return;
            
        createInorderList(inorderList, root->left);
        inorderList.push_back(root->val);
        createInorderList(inorderList, root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorderList;
        createInorderList(inorderList, root);
        return inorderList;
    }
};
