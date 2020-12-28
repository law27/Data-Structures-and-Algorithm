#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class Linked_List
{
private:
    node *head;
    node *tail;

public:
    Linked_List() : head(NULL), tail(NULL)
    {
    }

    void Insertion_at_the_End(int data)
    {
        node *temp = new node;
        temp->data = data;
        temp->next = NULL;

        if (head == NULL && tail == NULL)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    void Insertion_at_the_Front(int data)
    {
        node *temp = new node;
        temp->data = data;
        temp->next = NULL;

        node *ptr = head;
        head = temp;
        head->next = ptr;
    }

    void insertionAtTheGivenPosition(int data, int position)
    {

        if (position <= 1)
        {
            Insertion_at_the_Front(data);
        }
        else
        {
            node *insertion = new node();
            insertion->data = data;
            node *temp = head;
            for (int i = 1; i < position - 1; i++)
            {
                temp = temp->next;
            }
            node *ptr = temp->next;
            temp->next = insertion;
            insertion->next = ptr;
        }
    }

    void deletionAtTheFront()
    {
        node *temp = head;
        head = temp->next;
        delete temp;
    }

    void deletionAtTheEnd()
    {
        node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        tail = temp;
        delete temp->next;
        tail->next = NULL;
    }

    void deletionAtTheGivenPosition(int position)
    {
        node *temp = head;
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        node *deletable = temp->next;
        temp->next = deletable->next;
        delete deletable;
    }
    void Print()
    {
        cout<<"This prints the linked list"<<'\n';
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " --> ";
            temp = temp->next;
        }
        cout << endl;
    }
    friend void linkedListConcatenation(Linked_List &first, Linked_List &Second);
    friend void copyLinkedList(Linked_List &first, Linked_List &Second);
};

inline void linkedListConcatenation(Linked_List &first, Linked_List &Second)
{
    first.tail->next = Second.head;
}

void copyLinkedList(Linked_List &first, Linked_List &Second)
{
    node *temp_1 = first.head;
    while (temp_1 != NULL)
    {
        Second.Insertion_at_the_End(temp_1->data);
        temp_1 = temp_1->next;
    }
}

int main()
{
    Linked_List obj_1;
    Linked_List obj_2;
    obj_1.Insertion_at_the_Front(10);
    obj_1.Insertion_at_the_Front(20);
    obj_1.Insertion_at_the_Front(30);
    obj_1.Insertion_at_the_Front(40);
    obj_1.Insertion_at_the_Front(50);
    obj_1.Insertion_at_the_Front(60);
    copyLinkedList(obj_1, obj_2);
    linkedListConcatenation(obj_2, obj_1);
    obj_1.Print();
    obj_2.Print();
    return 0;
}
