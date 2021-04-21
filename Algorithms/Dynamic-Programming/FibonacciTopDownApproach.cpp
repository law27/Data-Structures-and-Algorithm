// A good algorithm will save you dozens of computing time
#include<bits/stdc++.h>
using namespace std;

int fib(int n, int *arr) {
    if(n == 0 || n == 1) {
        arr[n] = n;
        return arr[n];
    }
    if(arr[n] == 0) {
        arr[n] = fib(n - 1, arr) + fib(n - 2, arr);
    }
    return arr[n];
}

int fibWithoutDP(int n) {
    if(n <= 1) {
        return n;
    }
    return fibWithoutDP(n - 1) + fibWithoutDP(n - 2);
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n + 1] {0};
    auto start = chrono::steady_clock::now();
    cout << fib(n, arr) << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << "Program took With DP: " << chrono::duration <double, milli>(diff).count() << " ms" << endl;
    cout << endl;
    /* cout << "==== Dynamic Table ====" << endl;
    for(int i = 0; i <= n; i++) {
        cout << i << "th Fibonacci Number : " << arr[i] << endl;
    }*/
    start = chrono::steady_clock::now();
    cout << fibWithoutDP(n) << endl;
    end = chrono::steady_clock::now();
    diff = end - start;
    cout << "Program took With withoutDP: " << chrono::duration <double, milli>(diff).count() << " ms" << endl;
    return 0;
}
