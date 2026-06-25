/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 int height(struct TreeNode* root){
    if(root==NULL)
    return 0;
    int left=height(root->left);
    if(left==-1)
    return -1;
    int right=height(root->right);
    if(right==-1)
    return -1;
    if(abs(left-right)>1)
    return -1;
    return 1+(left>right?left:right);
 }
bool isBalanced(struct TreeNode* root) {
   return height(root)!= -1; 
}