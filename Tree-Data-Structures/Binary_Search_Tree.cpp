
/********************************************************************************************
*    Title: Binary Search Tree Soure Code                                                   *
*    Author: Lawrance J                                                                     *
*    Date: 17-11-2019                                                                       *
*    Availability: http://github.com/LawranceMichaelite/Data-Structures-and-Algorithm.git   *
*********************************************************************************************/

#include<iostream>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

class Binary_Search_Tree{
    private:
        node* root;
    
    node* New_Node(int data)
    {
        node* temp = new node();
        temp->data = data ;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }

    node* Insert_Node(int data,node* temp)
    {
        if(temp==NULL)
            temp = New_Node(data);
        else if( data > temp->data )
            temp->right = Insert_Node(data,temp->right);
        else
            temp->left = Insert_Node(data,temp->left);
        
        return temp;
    }
    public:
        Binary_Search_Tree() { root = NULL; }
    void Insert_Node(int data)
    {
        root = Insert_Node(data,root);
    }
    void Searching(int data)
    {
        node* temp = root;
        if(root==NULL)
            cout << "The tree is Empty" << endl;
        while(true)
        {
            if(temp==NULL)
            {
                cout << "Element is not Present in the Binary Tee" << endl;
                break;
            }
            else if(temp->data == data)
            {
                cout << "Element is Present" << endl;
                break;
            }
            else if( data > temp->data)
            {
                temp = temp->right ;
            }
            else 
            {
                temp = temp->left;
            }
        }
    
    }

    int get_Maximum()
    {
        node* temp = root;
        while(temp->right != NULL)
        {
            temp = temp->right;
        }
        return temp->data;
    }
    
    int get_Minimum()
    {
        node* temp = root;
        while(temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp->data;
    }
};

int main()
{
    Binary_Search_Tree a;
    a.Searching(100);
    a.Insert_Node(100);
    for( int i = 10 ; i > 0 ; i--){
        a.Insert_Node(i);
        a.Insert_Node(i+1);
    }
    a.Searching(10);
    a.Searching(11);
    a.Searching(5);
    a.Searching(100);
    a.Searching(101);
    cout << "The Maximum Element is: " << a.get_Maximum() << endl;
    cout << "The Minimum Element is: " << a.get_Minimum() << endl;
    return 0;
}