#include<iostream>
using namespace std;

struct node{
    int   data   ;
    node* left   ;
    node* right  ;
    int   height ;
};

class AVL_Tree
{
private:
    node* root;
    //Functions
    node* newNode(int data)
    {
        node* temp = new node;
        temp->data = data;
        temp->left = temp->right = NULL;
        temp->height = 1;
        return temp ;
    }
    node* addNode(int data , node* temp)
    {
        if(temp==NULL)
        {
            temp = newNode(data);
        }
        else if(data > temp->data)
        {
            temp->right = addNode(data,temp->right);
        }
        else
        {
            temp->left  = addNode(data,temp->left) ;
        }



        return temp;
    }
public:
    AVL_Tree()
    {
        root = NULL ;
    }
    node* addNode(int data)
    {
        root = addNode(data,root);
    }
};


int main()
{

}
