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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> result;
        inorder(root, k, result);
        return result.back();
    }
private:
    void inorder(TreeNode* node, int k, vector<int>& result){
        if(node==NULL) return;
        inorder(node->left, k, result);
        if(result.size()<k){
            result.push_back(node->val);
        }
        inorder(node->right, k, result);
    }
};
