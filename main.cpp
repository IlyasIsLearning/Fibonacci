#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;


long long fibonacciRecursive(int n) {
    if (n <= 1)
        return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}


long long fibonacciDP(int n) {
    if (n <= 1)
        return n;
    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}


void measureTimeRecursive(int n) {
    auto start = high_resolution_clock::now();
    long long result = fibonacciRecursive(n);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Fibonacci Recursive (n = " << n << ") = " << result << ", Time = " << duration.count() << " microseconds" << endl;
}


void measureTimeDP(int n) {
    auto start = high_resolution_clock::now();
    long long result = fibonacciDP(n);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Fibonacci Dynamic Programming (n = " << n << ") = " << result << ", Time = " << duration.count() << " microseconds" << endl;
}

int main() {
    int values[] = {10, 25, 30, 40, 50};

    cout << "Measuring Fibonacci Recursive Approach:" << endl;
    for (int n : values) {
        measureTimeRecursive(n);
    }

    cout << "\nMeasuring Fibonacci Dynamic Programming Approach:" << endl;
    for (int n : values) {
        measureTimeDP(n);
    }

    return 0;
}
