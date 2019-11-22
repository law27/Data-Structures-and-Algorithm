#include<iostream>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node* parent;
    char Color;
};

node* root = NULL;

node* New_Node(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->right = temp->left = temp->parent = NULL;
    temp->Color = 'R';
    return temp;
}

void Root_Should_Be_Black(node* temp)
{
    if(temp!=NULL)
    {
        temp->Color = 'B';
    }
}

void Parentization(node* temp)
{
    if(temp->left != NULL)
    {
        temp->left->parent = temp;
    }
    
    if(temp->right != NULL)
    {
        temp->right->parent = temp;
    }
}


void Red_Uncle_Condition(node* temp)
{
    if(temp->data > root->data)   //Left-Sub-tree
    {
        temp->Color = temp->parent->right->Color = 'B';
        temp->parent->Color = 'R';
    }
    else
    {
        temp->Color = temp->parent->left->Color = 'B';
        temp->parent->Color = 'R';
    }
    
}

void No_Uncle_Or_Black_Uncle_Condition(node* temp)
{

}

void No_Consecutive_Red(node* temp)
{
    if(temp->Color == 'R' && root != NULL)
    {
        //For Left-Sub-Tree
        if(temp->data < root->data )
        {
            if(temp->right != NULL )
            {
                if(temp->right->Color == 'R')
                {
                    if(temp->parent->right != NULL && temp->parent->right->Color == 'R')
                    {
                        Red_Uncle_Condition(temp);
                    }
                    else
                    {
                       No_Uncle_Or_Black_Uncle_Condition(temp); 
                    } 
                }
            }
            if(temp->left != NULL )
            {
                if(temp->left->Color == 'R')
                {
                    if(temp->parent->right != NULL && temp->parent->right->Color == 'R')
                    {
                        Red_Uncle_Condition(temp);
                    }
                    else
                    {
                       No_Uncle_Or_Black_Uncle_Condition(temp); 
                    } 
                }
            }
        }
        //For Right-Sub-Tree
        else
        {
            if(temp->right != NULL )
            {
                if(temp->right->Color == 'R')
                {
                    if(temp->parent->left != NULL && temp->parent->left->Color == 'R')
                    {
                        Red_Uncle_Condition(temp);
                    }
                    else
                    {
                       No_Uncle_Or_Black_Uncle_Condition(temp); 
                    } 
                }
            }
            if(temp->left != NULL )
            {
                if(temp->left->Color == 'R')
                {
                    if(temp->parent->left != NULL && temp->parent->left->Color == 'R')
                    {
                        Red_Uncle_Condition(temp);
                    }
                    else
                    {
                       No_Uncle_Or_Black_Uncle_Condition(temp); 
                    } 
                }
            }
        }
        
    }
}

node* Insert_Node(node* temp, int data)
{
    if(temp==NULL)
    {
        temp = New_Node(data);
    }
    else if(data > temp->data)
    {
        temp->right = Insert_Node(temp->right , data);
    }
    else
    {
        temp->left = Insert_Node(temp->left , data);
    }

    Root_Should_Be_Black(root);
    Parentization(temp);
    No_Consecutive_Red(temp);

    return temp;
}

int main()
{
        root = Insert_Node(root, 10);
        root = Insert_Node(root,5);
        root = Insert_Node(root,15);
        root = Insert_Node(root,25);
        root = Insert_Node(root,4);
        root = Insert_Node(root,14);
        root = Insert_Node(root,27);
        
        cout << root->data << " --> " << root->Color << endl;
        cout << root->left->data << " --> " << root->right->Color << endl;
        cout << root->right->data << " --> " << root->right->Color << endl;
        cout << root->right->right->data << " --> " << root->right->right->Color << endl;
        cout << root->right->left->data << " --> " << root->right->left->Color << endl;
        cout << root->left->left->data << " --> " << root->left->left->Color << endl;
        cout << root->right->right->right->data << " --> " << root->right->right->right->Color << endl;
        return 0;
}