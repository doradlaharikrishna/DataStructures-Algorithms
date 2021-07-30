/**
Question:
Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).

 

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []
 
Constraints:
The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        
        // Handle Zero nodes case
        if (root == NULL)
            return res;
        
        queue<TreeNode*> que;
        que.push(root);
        vector<int> temp;
        while(!que.empty()) {
            int size = que.size();
            TreeNode* tempnode;
            for(int i=0;i<size;i++) {
                tempnode = que.front();
                temp.push_back(tempnode->val);
                
                if(tempnode->left != NULL)
                    que.push(tempnode->left);
                if(tempnode->right != NULL)
                    que.push(tempnode->right);
                
                que.pop();
            }
            res.push_back(temp);
            temp.clear();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
