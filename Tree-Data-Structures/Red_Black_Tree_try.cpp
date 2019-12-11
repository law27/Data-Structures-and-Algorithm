#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node *parent;
    char Color;
};

node *root = NULL;

node *New_Node(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->right = temp->left = temp->parent = NULL;
    temp->Color = 'R';
    return temp;
}

void Root_Should_Be_Black(node *temp)
{
    if (temp != NULL)
    {
        temp->Color = 'B';
    }
}

void Parentization(node *temp)
{
    if (temp->left != NULL)
    {
        temp->left->parent = temp;
    }

    if (temp->right != NULL)
    {
        temp->right->parent = temp;
    }
}

void Red_Uncle_Condition(node *temp)
{
    if (temp->data < temp->parent->data) //Left-Sub-tree
    {
        temp->Color = 'B';
        temp->parent->right->Color = 'B';
        temp->parent->Color = 'R';
    }
    else
    {
        temp->Color = 'B';
        temp->parent->left->Color = 'B';
        temp->parent->Color = 'R';
    }
}
void No_Uncle_Or_Black_Uncle_Condition(node *temp);

void No_Consecutive_Red(node *temp)
{
    if (temp->data < temp->parent->data) //Left-SubTree
    {
        if (temp->parent->right != NULL)
        {
            if (temp->parent->right->Color == 'R')
            {
                Red_Uncle_Condition(temp);
            }
            else
            {
                No_Uncle_Or_Black_Uncle_Condition(temp);
            }
        }
        else
        {
            cout << "Hello" << endl;
            No_Uncle_Or_Black_Uncle_Condition(temp);
        }
    }

    else
    {
        if (temp->parent->left != NULL)
        {
            if (temp->parent->left->Color == 'R')
            {
                Red_Uncle_Condition(temp);
            }
            else
            {
                No_Uncle_Or_Black_Uncle_Condition(temp);
            }
        }
        else
        {
            No_Uncle_Or_Black_Uncle_Condition(temp);
        }
    }
}
node *Left_Rotation(node *temp)
{
    node *x = temp->right;
    node *y = x->left;

    x->left = temp;
    temp->right = y;

    return x;
}

node *Right_Rotation(node *temp)
{
    node *x = temp->left;
    node *y = x->right;

    x->right = temp;
    temp->left = y;

    return x;
}

void No_Uncle_Or_Black_Uncle_Condition(node *temp)
{
    if (temp->data < temp->parent->data) //Left-Sub-Tree
    {
        if (temp->right != NULL)
        {
            if (temp->right->Color == 'R')
            {
                temp->parent->left = Left_Rotation(temp->parent->left);
                Right_Rotation(temp->parent);
            }
        }

        if (temp->left != NULL)
        {
            if (temp->left->Color == 'R')
            {
                Right_Rotation(temp->parent);
            }
        }
    }

    else //Right-Sub-Tree
    {
        if (temp->right != NULL)
        {
            if (temp->right->Color == 'R')
            {
                Left_Rotation(temp->parent);
            }
        }

        if (temp->left != NULL)
        {
            if (temp->left->Color == 'R')
            {
                temp->parent->right = Right_Rotation(temp->parent->right);
                Left_Rotation(temp->parent);
            }
        }
    }
}

node *Insert_Node(node *temp, int data)
{
    if (temp == NULL)
    {
        temp = New_Node(data);
    }
    else if (data > temp->data)
    {
        temp->right = Insert_Node(temp->right, data);
    }
    else
    {
        temp->left = Insert_Node(temp->left, data);
    }

    Root_Should_Be_Black(root);
    Parentization(temp);
    if (temp->Color == 'R')
    {
        if (temp->right != NULL || temp->left != NULL)
        {
            if (temp->right->Color == 'R' || temp->left->Color == 'R')
            {
                No_Consecutive_Red(temp);
            }
        }
    }

    return temp;
}

node *Searching(int data)
{
    node *temp = root;
    if (root == NULL)
        cout << "The tree is Empty" << endl;
    while (true)
    {
        if (temp == NULL)
        {
            cout << "Element is not Present in the Binary Tee" << endl;
            break;
        }
        else if (temp->data == data)
        {
            cout << "Element is Present" << endl;
            return temp;
            break;
        }
        else if (data > temp->data)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
}

int main()
{
    root = Insert_Node(root, 10);
    root = Insert_Node(root, 9);
    root = Insert_Node(root, 8);
    cout << "Hello" << endl;
    return 0;
}