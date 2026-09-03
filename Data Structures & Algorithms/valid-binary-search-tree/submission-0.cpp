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
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }
private:
    bool validate(TreeNode* node, long long mini, long long maxi){
        if(node==NULL) return true;

        if(node->val<=mini || node->val>=maxi){
            return false;
        }

        bool left_valid=validate(node->left,mini, node->val);
        bool right_valid=validate(node->right,node->val,maxi);

        return left_valid && right_valid;
    }
};
