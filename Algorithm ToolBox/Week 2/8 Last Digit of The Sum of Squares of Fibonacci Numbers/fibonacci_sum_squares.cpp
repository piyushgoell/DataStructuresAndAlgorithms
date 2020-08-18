#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;
    long long sum = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}
int fibonacci_sum_squares_fast(long long n) {
    // The length of Pisano Period for fibonacci number mod 10 is 60
    // You can check my previous solution to know more about Pisano period
    // it means the after 60 iterations the fibonacci number mod 10  will repeat
    // So, we only need to compute for n % 60 

    //  Initial Condition: 
    //  for value {0,1} the result will be same as we know fibonacci series  0,1,2,3,5,8,13......
    if (n % 60 <= 1)
        return n % 60;

    // The Number of Iterations we need to perform
    int iterations = n % 60;

    // Initial values:
    int a = 0, b = 1;
    int ans = 0, sum = 1;

    // Loop to generate the Fibonacci Numbers
    for (int i = 1; i < iterations; i++) {
        ans = (a + b) % 10;
        a = b;
        b = ans;
        sum += (ans * ans);
    }
    return sum % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_squares_naive(n);
    std::cout << fibonacci_sum_squares_fast(n);
}
