#include<iostream>
using namespace std;

struct node
{
    char data;
    node* next;
};


class Stack
{
private:
    node* head;

public:
    Stack()
    {
        head = NULL;
    }

    void push(char data)
    {
        node* temp = new node;
        temp->data = data;
        temp->next = NULL;

        node* ptr = head;
        head = temp;
        head->next = ptr;
    }

    int top()
    {
        return head->data;
    }

    void pop()
    {
        node* temp = head;
        head = temp->next;
        delete temp;
    }
};


int main()
{
    Stack stack;
    //Everything will be filled here ASAP    
    return 0;
}