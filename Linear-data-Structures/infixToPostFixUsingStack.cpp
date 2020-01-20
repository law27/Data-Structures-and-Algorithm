#include<iostream>
using namespace std;
string result;

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

    char top()
    {
        return head->data;
    }

    char pop()
    {
        node* temp = head;
        head = temp->next;
        char a = temp->data;
        delete temp;
        return a;
    }
};

bool checkForPrescedance(char a, char b)
{
    
}

bool checkForOperators(char a)
{
    if (a == '*' || a == '-' || a == '/' || a == '+')
    {
        return true;
    }
    return false;
}

int main()
{
    Stack stack;
    string value = "";
    cin >> value;
    result = "";
    for (unsigned int i = 0; i < value.length(); i++)
    {
        if (value[i] == '(')
        {
            stack.push('(');
        }
        else if (value[i] == ')')
        {
            while (stack.top() != '(')
            {
                result += stack.pop();
            }
            stack.pop();
        }
        else if (checkForOperators(value[i]))
        {
            if (checkForOperators(stack.top()))
            {
                while (checkForPrescedance(stack.top(), value[i]))
                {
                    result += stack.pop();
                }
                    stack.push(value[i]);
            }
            else
            {
                stack.push(value[i]);
            }
        }
        else
        {
            result += value[i];
        }
    }
        

    return 0;
}