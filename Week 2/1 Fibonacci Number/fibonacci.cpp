#include <iostream>
#include <cassert>

int fibonacci_naive(int n) {
	if (n <= 1)
		return n;
	return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int fibonacci_fast(int n) {
	if (n == 0 || n == 1)
		return n;
	int a = 0, b = 1;
	int ans = 1;
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
