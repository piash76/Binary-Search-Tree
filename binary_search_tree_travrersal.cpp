

///in-order= left - root - right (sorted)

///pre-order=root - left - right (dfs)

///post-order= left - right - root


void inorder(Node *cur_node)
{
  if (cur_node==NULL) return;

  inorder(cur_node->left);

  cout << cur_node->data << " ";


  inorder(cur_node->right);
}

void preorder(Node* cur_node)
{
    if(cur_node==NULL) return;

    cout<<cur_node->data<<" ";

    preorder(cur_node->left);
    preorder(cur_node->right);
}


void postorder(Node* cur_node)
{
    if(cur_node==NULL) return;

    postorder(cur_node->left);
    postorder(cur_node->right);

    cout<<cur_node->data<<" ";

}

