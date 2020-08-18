#include <iostream>

int get_change(int m) {
	int count = 0;
	(m >= 10) ? (count += m / 10, m %= 10) : (count += 0);
	(m >= 5) ? (count += m / 5, m %= 5) : (count += 0);
	(m >= 0) ? (count += m / 1, m %= 1) : (count += 0);

	return count;
}

int main() {
	int m;
	std::cin >> m;
	std::cout << get_change(m) << '\n';
}
