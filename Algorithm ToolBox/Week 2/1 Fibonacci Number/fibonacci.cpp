#include <iostream>
#include <cassert>

int fibonacci_naive(int n) {
	if (n <= 1)
		return n;
	return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int fibonacci_fast(int n) {
	//  Initial Condition: 
	//  for value {0,1} the result will be same as we know fibonacci series  0,1,2,3,5,8,13......
	if (n == 0 || n == 1)
		return n;
	//	Initaial values:
	int a = 0, b = 1;
	int ans = 1;
	// Loop to generate the Fibonacci Numbers
	for (int i = 2; i <= n; i++) {
		ans = a + b;
		a = b;
		b = ans;
	}
	return ans;
}

int main() {
	int n = 0;
	std::cin >> n;
	//std::cout << fibonacci_naive(n) << '\n';
	std::cout << fibonacci_fast(n) << '\n';
	return 0;
}
