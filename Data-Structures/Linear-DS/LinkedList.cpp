#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

class LinkedList {
private:
    node *head;
    node *tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        node* temp = head;
        while (temp != nullptr) {
            node* val = temp;
            temp = temp->next;
            delete val;
        }

        delete head;
        delete tail;
    }

    void insertionAtTheEnd(int data) {
        node *temp = new node;
        temp->data = data;
        temp->next = nullptr;

        if (head == nullptr && tail == nullptr)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    void insertionAtTheFront(int data) {
        node *temp = new node;
        temp->data = data;
        temp->next = nullptr;

        node *ptr = head;
        head = temp;
        head->next = ptr;
    }

    void insertionAtTheGivenPosition(int data, int position) {
        if (position <= 1) {
            insertionAtTheFront(data);
        }
        else {
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

    void deletionAtTheFront() {
        node *temp = head;
        head = temp->next;
        delete temp;
    }

    void deletionAtTheEnd() {
        node *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        tail = temp;
        delete temp->next;
        tail->next = nullptr;
    }

    void print() {
        node *temp = head;
        while (temp != nullptr) {
            cout << temp->data << " --> ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    LinkedList linkedList;
    linkedList.insertionAtTheFront(1);
    linkedList.insertionAtTheFront(2);
    linkedList.insertionAtTheFront(3);
    linkedList.insertionAtTheFront(4);
    linkedList.insertionAtTheFront(5);
    linkedList.insertionAtTheFront(6);
    linkedList.print();
    return 0;
}
