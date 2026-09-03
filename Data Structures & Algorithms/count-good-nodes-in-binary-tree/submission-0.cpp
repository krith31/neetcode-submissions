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
    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0;

        return countgood(root, root->val);
    }
private:
    int countgood(TreeNode* node, int maxi){
        if(node==NULL) return 0;
        int good=0;

        if(node->val>=maxi){
            good=1;
            maxi=node->val;
        }

        good+=countgood(node->left,maxi);
        good+=countgood(node->right,maxi);
        return good;
    }
};
