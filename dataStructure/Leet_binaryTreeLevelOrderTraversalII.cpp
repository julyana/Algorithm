/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> vec;
    
    void levelOrderTop(TreeNode* root, int len) {
        if (root == NULL) return ;
        if (len == vec.size()) {
            vector<int> vecInside;
            vec.push_back(vecInside);
        }
        vec[len].push_back(root -> val);
        if (root -> left != NULL) 
          levelOrderTop(root -> left, len + 1);
        if (root -> right != NULL) 
          levelOrderTop(root -> right, len + 1);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        levelOrderTop(root, 0);
        return vector<vector<int> >(vec.rbegin(), vec.rend());
    }
    
};
