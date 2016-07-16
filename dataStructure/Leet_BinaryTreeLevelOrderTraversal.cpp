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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q1;  
        vector<vector<int>>ovec;  
        vector<int>ivec;  
        TreeNode *temp = root;  
        if(!temp)
            return ovec;  
        q1.push(temp);  
        do {  
            queue<TreeNode*>q2;
            while (!q1.empty())  
            {  
                temp = q1.front();  
                ivec.push_back(temp->val);  
                q1.pop();  
                if (temp->left)  
                    q2.push(temp->left);  
                if (temp->right)  
                    q2.push(temp->right);  
            }  
            ovec.push_back(ivec);  
            ivec.clear();  
            q1 = q2;  
        } while (!q1.empty());  
        return ovec;  
    }  
};
