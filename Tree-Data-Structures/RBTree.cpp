#include <iostream>
using namespace std;

struct node
{
    int data;
    char color;
    node *left;
    node *right;
    node *parent;
};

node *root = NULL;

node *newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = temp->right = temp->parent = NULL;
    return temp;
}

void leftRotate(node *x)
{
    node *y = x->right;
    x->right = y->left;
    if (y->left != NULL)
    {
        y->parent->left = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL)
    {
        root = y;
    }
    else if (x == x->parent->left)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void rightRotate(node *x)
{
    node *y = x->left;
    x->left = y->right;
    if (y->right != NULL)
    {
        y->parent->right = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL)
    {
        root = y;
    }
    else if (x == x->parent->left)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }
    y->right = x;
    x->parent = y;
}

void insertFixUp(node *x)
{
    x->color = 'R';
    while (x != root && x->parent != root && x->parent->color == 'R')
    {
        if (x->parent == x->parent->parent->left)
        {
            node *uncle = x->parent->parent->right;
            if (uncle != NULL && uncle->color == 'R')
            {
                uncle->color = 'B';
                x->parent->color = 'B';
                x->parent->parent->color = 'R';
                x = x->parent->parent;
            }
            else
            {
                if (x == x->parent->right)
                {
                    x = x->parent;
                    leftRotate(x);
                }
                x->parent->color = 'B';
                x->parent->parent->color = 'R';
                rightRotate(x->parent->parent);
            }
        }
        else
        {
            node *uncle = x->parent->parent->left;
            if (uncle != NULL && uncle->color == 'R')
            {
                uncle->color = 'B';
                x->parent->color = 'B';
                x->parent->parent->color = 'R';
                x = x->parent->parent;
            }
            else
            {
                if (x == x->parent->left)
                {
                    x = x->parent;
                    rightRotate(x);
                }
                x->parent->color = 'B';
                x->parent->parent->color = 'R';
                leftRotate(x->parent->parent);
            }
        }
    }
    root->color = 'B';
}

void createNode(int data)
{
    if (root == NULL)
    {
        root = newNode(data);
        root->parent = NULL;
    }
    else
    {
        node *childNode = newNode(data);
        node *temp = root;
        node *parents = NULL;
        while (temp != NULL)
        {
            parents = temp;
            if (data > temp->data)
                temp = temp->right;
            else
                temp = temp->left;
        }
        childNode->parent = parents;
        if (childNode->data > parents->data)
        {
            parents->right = childNode;
        }
        else
        {
            parents->left = childNode;
        }
        insertFixUp(childNode);
    }
}

void printTree(node *x)
{
    if (x != NULL)
    {
        cout << "Data: " << x->data << endl;
        cout << "Color:  " << x->color << endl;
        if (x->parent != NULL)
            cout << "Parent: " << x->parent->data << endl;
        cout << endl;
        printTree(x->left);
        printTree(x->right);
    }
}

int main()
{
    createNode(4);
    createNode(1);
    createNode(2);
    printTree(root);
    return 0;
}
