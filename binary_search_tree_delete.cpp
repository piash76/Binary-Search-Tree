

Node* getmin(Node *cur)
{
    while(cur->left!=NULL)
    {
        cur=cur->left;
    }

    return cur;
}

Node* deleting(Node *cur,int val)
{
    if(cur==NULL) return NULL;
    else if(val<cur->data)
    {
        cur->left=deleting(cur->left,val);

    }
    else if(val>cur->data)
    {
        cur->right=deleting(cur->right,val);
    }
    else
    {
        ///found the node to be deleted
        ///if it is leaf node or no child

        if(cur->left==NULL and cur->right==NULL)
        {
            delete cur;

            return NULL;
        }
        else if(cur->left==NULL)
        {
            ///has right child only
            Node *temp=cur;
            cur=cur->right;
            delete temp;

            return cur;
        }
        else if(cur->right==NULL)
        {
            ///has left child only
            Node *temp=cur;
            cur=cur->left;
            delete temp;

            return cur;
        }
        else
        {
            ///2 child
            ///find the min in right sub-tree by going to the left side from that
            Node* temp=getmin(cur->right);
            cur->data=temp->data;

            cur->right=deleting(cur->right,temp->data);

        }
    }

}
