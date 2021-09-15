map<int,int> m;
int idx;

 TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    int n=preorder.size();

    for(int i=0;i<n;i++)
    {
        m[inorder[i]]=i;
    }

    return create(preorder,0,n-1);

}

TreeNode* create(vector<int>& preorder,int lft,int rt)
{
    if(lft>rt) return NULL;

    TreeNode *temp_root=new TreeNode;

    temp_root->val=preorder[idx];


    int mid=m[preorder[idx]];

    idx++;

    temp_root->left=create(preorder,lft,mid-1);
    temp_root->right=create(preorder,mid+1,rt);

    return temp_root;

}
