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

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        depthfs(root, diameter);        
        return diameter;
    }

    int depthfs(TreeNode* current, int& diameter)
    {
        if(current==nullptr)
            return 0;

        int left = depthfs(current->left, diameter);
        int right = depthfs(current->right, diameter);
        diameter = max(diameter, left+right);
        cout << diameter;
        return  1 + max(left,right);
    }
};
