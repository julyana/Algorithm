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
    bool flag = true;
    int dfs(TreeNode* root) {
        if (root == NULL) return 0;
        int l, r;
        if (root -> left == NULL) {
            l = 0;
        } else {
            l = dfs(root -> left);
        }
        if (root -> right == NULL) {
            r = 0;
        } else {
            r = dfs(root -> right);
        }
        if (abs(l - r) > 1) flag = false;
        return l > r ? l + 1: r + 1;
    }
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return flag;
    }
};
