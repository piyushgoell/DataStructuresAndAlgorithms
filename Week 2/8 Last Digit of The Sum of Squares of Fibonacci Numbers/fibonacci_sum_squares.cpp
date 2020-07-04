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
    if (n % 60 <= 1)
        return n % 60;

    int iterations = n % 60;
    int a = 0, b = 1;
    int ans = 0, sum = 1;

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
