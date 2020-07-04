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

    if (to % 60 <= 1)
        return to % 60;

    from = from % 60;
    to = to % 60;

    if (from > to)
        to += 60;

    int a = 0, b = 1;
    int ans = 0, sum = 0;
    if (from <= 1)
        sum = 1;
    for (int i = 1; i < to; i++) {
        ans = (a + b) % 10;
        a = b;
        b = ans;
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
