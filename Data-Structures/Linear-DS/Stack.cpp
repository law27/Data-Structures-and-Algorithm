#include <iostream>
using namespace std;

template <class Type>
class Stack {
protected:
    const string UNDERFLOW        = "underflow";
    const string OVERFLOW         = "overflow";
    int pointer = 0;
    void throwError(const string& type) {
        if(type == "underflow") {
            throw underflow_error("Stack doesn't have a value");
        }
        else if(type == "overflow") {
            throw overflow_error("Stack Size reached");
        }
    }
public:
    virtual void push(Type value) = 0;
    virtual void pop()            = 0;
    virtual Type top()            = 0;
    virtual inline int  size()    = 0;
};

template <class Type>
class ArrayStack: public Stack<Type> {
private:
    Type *stackArray;
    int length{};

public:
    explicit ArrayStack(int length) {
        this->length = length;
        stackArray = new Type[this->length];
    }
    void push(Type value) override {
        if(length == this->pointer) {
            this->throwError(this->OVERFLOW);
        }
        else {
            stackArray[(this->pointer)++] = value;
        }
    }
    void pop() override {
        if(this->pointer == 0) {
            this->throwError(this->UNDERFLOW);
        }
        else {
            --(this->pointer);
        }
    }
    Type top() override {
        return stackArray[this->pointer - 1];
    }
    inline int size() override {
        return this->pointer;
    }
};

template <class Type>
class LinkedListStack: public Stack<Type> {
private:
    struct Element {
        Type data;
        Element* next;
    };
    int pointer;
    Element *head;
public:
    explicit LinkedListStack() {
        pointer = 0;
        head = nullptr;
    }
    void push(Type element) override {
        if(head == nullptr) {
            head = new Element();
            head->data = element;
            head->next = nullptr;
        }
        else {
            auto* temp = new Element();
            temp->data = element;
            temp->next = head;
            head = temp;
        }
        ++pointer;
    }
    void pop() override {
        if(head == nullptr) {
            this->throwError(this->UNDERFLOW);
        }
        else {
            Element* temp = head;
            head = head->next;
            free(temp);
            --pointer;
        }
    }
    Type top() override {
        if(head == nullptr) {
            this->throwError(this->UNDERFLOW);
        }
        else {
            return head->data;
        }
    }
    inline int size() override {
        return pointer;
    }
};

int main() {
    Stack<int> *arr = new ArrayStack<int>(10);
    Stack<int> *list = new LinkedListStack<int>();
    arr->push(10);
    list->push(10);
    arr->push(20);
    list->push(20);
    arr->push(30);
    list->push(30);
    cout << boolalpha << (arr->top() == list->top()) << endl;
    arr->pop();
    list->pop();
    cout << boolalpha << (arr->top() == list->top()) << endl;
    cout << boolalpha << (arr->size() == list->size()) << endl;
    return 0;
}
