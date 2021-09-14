

 int maxDepth(TreeNode* root)
{

    if(root==NULL) return 0;

    int mx=max(1+maxDepth(root->left),1+maxDepth(root->right));

    return  mx;

}
