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
    
    int helper(TreeNode *root, int res){
        int newRes = res << 1 | root->val;
        if(root->right == NULL && root->left == NULL){ return newRes; }
        int sum = 0;
        if(root->left!=NULL){ sum+=helper(root->left, newRes); } 
        if(root->right!=NULL){ sum+=helper(root->right, newRes); }
        return sum;
    }
    
    int sumRootToLeaf(TreeNode* root) {
        return helper(root, 0);   
    }
};
