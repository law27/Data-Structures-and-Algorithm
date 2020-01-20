#include<iostream>
using namespace std ;

struct node
{
    int data ;
    node* next ;
} ;

class Stack
{
    private:
        node* head ;
    public:
        Stack()
        {
            head = NULL ;
        }
    void push(int data)
    {
        node* temp = new node() ;
        temp->data = data ;
        temp->next = NULL ;

        temp->next = head ;
        head = temp ;
    }
    int pop()
    {
        node* temp = head ;
        head = temp->next ;
        int data = temp->data ;
        delete temp ;
        return data ;
    }
    int top()
    {
        if(head == NULL)
            return 0 ;
        else
            return head->data ;
    }
    bool isEmpty()
    {
        return ( head == NULL ) ? true : false ;
    }

};

int main()
{
    Stack stack ;
    int n ;
    while( cin >> n )
    {
        if( n == 0)
            break ;
        else
        {
            stack.push(n) ;
        }   
    }
    cout << stack.pop() << endl ;
    cout << stack.pop() << endl ;
    cout << stack.top() << endl ;
    cout << stack.pop() << endl ;
    if(stack.isEmpty())
    {
        cout << "Stack is Empty" << endl ;
    }
    return 0;
}