


///bari
///https://drive.google.com/drive/u/0/folders/1U36JvWLe0Vu2-JIo2Jt7stEYry-AZxpj



///implemantion delete
///https://www.youtube.com/watch?v=gcULXE7ViZw

#include<bits/stdc++.h>

using namespace std;


struct Node
{
    int data;
    Node *left;
    Node *right;
};


Node* getpos(Node *cur, int val)
{
  if (val<cur-> data)
  {
    if (cur->left == nullptr) return cur;
    return getpos(cur->left, val);
  }
  else
  {
    if (cur->right == nullptr) return cur;
    return getpos(cur->right, val);
  }
}


Node* create()
{
    Node *root=NULL;

    while(1)
    {
        int user_data;cin>>user_data;
        if(user_data==-1) break;

        Node *cur=new Node;
        cur->data=user_data;
        cur->left=NULL;
        cur->right=NULL;


        if (root == nullptr)
        {
           root=cur;
        }
        else
        {
          Node *temp=getpos(root,user_data);

          if (user_data<temp->data)
          {
             temp->left=cur;
          }
          else
          {
             temp->right=cur;
          }
        }


    }

    return root;
}





void inorder(Node *cur_node)
{
  if (cur_node==NULL) return;

  inorder(cur_node->left);

  cout << cur_node->data << " ";


  inorder(cur_node->right);
}


Node* searching(Node* cur,int val)
{
    if(cur==NULL) return NULL;

    if(cur->data==val)
    {
        return cur;
    }

    if(val<cur->data)
    {
        return searching(cur->left,val);
    }
    else
    {
        return searching(cur->right,val);
    }

}


///inorder succesor of a node is the node that comes after  in in-order traversal
///min of right subtree


Node* inorder_successor(Node *cur,Node *root)
{
    if(cur->right!=NULL)
    {
        ///min of right subtree

        Node *temp=cur->right;


        while(temp->left!=NULL)
        {
            temp=temp->left;
        }

        return temp;

    }
    else
    {
        ///it can be the leaf node of left sub-tree same
        ///it can the leaf node of right sub-tree last left e dukar time e je node chilo oitai er next node

        Node *last_par;
        Node *temp=root;

        while(temp->data!=cur->data)
        {
            if(cur->data<temp->data)
                temp=temp->left;
            }
            else
            {
                temp=temp->right;
            }
        }


        return last_par;

    }
}

      {
                last_par=temp;

                temp=temp->left;
            }
            else
            {
                temp=temp->right;
            }
        }


        return last_par;

    }
}



int main()
{

    Node *root=create();

    ///searching(root,17);
    inorder(root);
    cout<<endl;

   Node *temp=searching(root,34);

   Node *succ=inorder_successor(temp,root);

   cout<<succ->data<<endl;


   return 0;

}

/*

11
6
8
19
4
17
43
-1


11 6 8 10 19 4 17 43 -1


25 15 50 10 22 35 70 -1

25 15 50 10 22 35 34 36 70 69 71 -1

*/

