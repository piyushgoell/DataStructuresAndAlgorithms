#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

// Function to calculate the length pisabo period for Fibonaci Number
long long get_pisano_period(long long m) {
    long long a = 0, b = 1, c = a + b;
    for (int i = 1; i <= m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1)
            return i;
    }
}
int get_fibonacci_huge_fast(long long n, long long m) {

    //	To get the length of fibonacci Number after which it repeates itself.
    m = get_pisano_period(m);

    //  Initial Condition: 
    //  for value {0,1} the result will be same as we know fibonacci series  0,1,2,3,5,8,13......
    if (n % m <= 1)
        return n % m;

    // The Number of Iterations we need to perform
    long long iterations = n % m;

    // Initial values:
    long long a = 0, b = 1;
    long long ans = 0;

    // Loop to generate the Fibonacci Numbers
    for (long long i = 1; i < iterations; i++) {
        ans = (a + b) % m;
        a = b;
        b = ans;
    }
    return ans % m;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';

}
