#include <iostream>
using namespace std;

template<typename Type>
class Stack {

private:
    int maxSize;
    int currentLength = 0;
    Type* utilityArray;

public:
    explicit Stack(int max) : maxSize(max), utilityArray(new Type[maxSize]) {}

    void push(Type);

    void pop();

    Type peek();

    bool isEmpty();
};

template<typename Type>
void Stack<Type>::push(Type element) {
    if(currentLength >= maxSize) {
        cerr << "Max Overflow" << endl;
        exit(1);
    }
    else {
        utilityArray[currentLength++] = element;
    }
}

template<typename Type>
void Stack<Type>::pop() {
    if(currentLength <= 0) {
        cerr << "No element is inside the Stack" << endl;
        exit(1);
    }
    else {
        currentLength--;
    }
}

template<typename Type>
Type Stack<Type>::peek() {
    if(currentLength <= 0) {
        cerr << "No element is inside the Stack" << endl;
        exit(1);
    }
    else {
        return utilityArray[currentLength - 1];
    }
}

template<typename Type>
bool Stack<Type>::isEmpty() {
    return currentLength == 0;
}

int main() {
    Stack<string> object(10);
    cout << boolalpha << object.isEmpty() << endl;
    object.push("Lawrence");
    object.push("Github");
    cout << object.peek() << endl;
    object.pop();
    cout << object.peek() << endl;
    cout << boolalpha << object.isEmpty() << endl;
    object.pop();
    return 0;
}
