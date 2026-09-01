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
        int max_diam=0;
        diam(root, max_diam);
        return max_diam;
    }
private:
    int diam(TreeNode* node, int& max_diam){
        if(node==nullptr) return 0;

        int left=diam(node->left, max_diam);
        int right=diam(node->right, max_diam);
        max_diam=max(max_diam,left+right);

        return 1+max(left,right);
    }
};
