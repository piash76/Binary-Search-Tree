
#include<bits/stdc++.h>

using namespace std;

int in[100005],pre[100005],idx;

struct Node
{
    int data;
    Node *left;
    Node *right;
};


Node* create(int lft,int rt)
{
    if(lft>rt) return NULL;

    Node *temp_root=new Node;
    temp_root->data=pre[idx];


    int mid;
    for(int i=lft;i<=rt;i++)
    {
        if(pre[idx]==in[i])
        {
            mid=i;break;

        }
    }
    idx++;

    temp_root->left=create(lft,mid-1);
    temp_root->right=create(mid+1,rt);

    return temp_root;

}



void inorder(Node *cur_node)
{
  if (cur_node==NULL) return;

  inorder(cur_node->left);

  cout << cur_node->data << " ";


  inorder(cur_node->right);
}


int main()
{
    int n;cin>>n;

    for(int i=0;i<n;i++) cin>>in[i];
    for(int i=0;i<n;i++) cin>>pre[i];

    Node *root=create(0,n-1);

    inorder(root);

}

/*


6
3 1 4 0 5 2
0 1 3 4 2 5

8
4 2 1 7 5 8 3 6
1 2 4 3 5 7 8 6


*/
