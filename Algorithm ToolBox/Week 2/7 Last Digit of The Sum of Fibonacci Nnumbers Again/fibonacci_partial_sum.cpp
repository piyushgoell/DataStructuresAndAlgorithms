#include <iostream>
#include <vector>
using std::vector;
using namespace std;
long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

int get_fibonacci_partial_sum_fast(long long from, long long to) {
    // The length of Pisano Period for fibonacci number mod 10 is 60
   // You can check my previous solution to know more about Pisano period
   // it means the after 60 iterations the fibonacci number mod 10  will repeat
   // So, we only need to compute for n % 60 

   //  Initial Condition: 
   //  for value {0,1} the result will be same as we know fibonacci series  0,1,2,3,5,8,13......
    if (to % 60 <= 1)
        return to % 60;

    // As the sequence repeats itself after 60 numbers
    // So, we only need to calculate the sequence which is left after n * 60 repetations 
    // i.e. Remainder when divided by 60 
    from = from % 60;
    to = to % 60;

    // Correction statement:
    if (from > to)
        to += 60;

    // Initial values:
    int a = 0, b = 1;
    int ans = 0, sum = 0;

    // To solve the issue of two ones at the begining of the Fibonacci series. 
    if (from <= 1)
        sum = 1;

    // Loop to generate the Fibonacci Numbers
    for (int i = 1; i < to; i++) {
        ans = (a + b) % 10;
        a = b;
        b = ans;

        // Condition to start calculating the sum
        if ((i + 1) >= from) {
            sum += ans;
        }
    }
    return sum % 10;
}


int main() {
    long long from, to;
    std::cin >> from >> to;
    //std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
