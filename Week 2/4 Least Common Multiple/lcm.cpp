#include <iostream>

long long lcm_naive(int a, int b) {
    for (long l = 1; l <= (long long)a * b; ++l)
        if (l % a == 0 && l % b == 0)
            return l;

    return (long long)a * b;
}
//	Function to calculate the gcd of two numbers
int gcd_fast(int a, int b) {
    return b ? gcd_fast(b, a % b) : a;
}

long long lcm_fast(long long a, long long b)
{
    //	formula: LCM = x / gcd(x,y);
    return a / gcd_fast(a, b) * b;
}

int main() {
    int a, b;
    std::cin >> a >> b;
    //	std::cout << lcm_naive(a, b) << std::endl;
    std::cout << lcm_fast(a, b) << std::endl;
    return 0;
}
