/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int targetSum) {
    if(root==NULL)
    return false;
    if(root->left==NULL && root->right==NULL){
        if(targetSum==root->val)
        return true;
        else
        return false;
    }
    int newTarget=targetSum-root->val;
    return hasPathSum(root->left,newTarget)|| hasPathSum(root->right,newTarget);
}