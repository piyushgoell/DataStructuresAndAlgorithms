#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
//using std::max;

int compute_min_refills(int dist, int fullTank, vector<int>& stops) {
	// write your code here
	int refillCount = 0;
	int currentRefillLocation = 0;
	int currentIndex = 0;

	while (currentIndex <= stops.size()) {

		while ((currentIndex < stops.size()) && (stops[currentIndex] - currentRefillLocation <= fullTank))
			currentIndex += 1;

		if (currentRefillLocation + fullTank >= dist)
			return refillCount;

		if (currentRefillLocation == stops[currentIndex - 1])
			return -1;

		refillCount += 1;
		currentRefillLocation = stops[currentIndex - 1];
	}
	return refillCount;
}


int main() {
	int d = 0;
	cin >> d;
	int m = 0;
	cin >> m;
	int n = 0;
	cin >> n;

	vector<int> stops(n);
	for (size_t i = 0; i < n; ++i)
		cin >> stops.at(i);

	cout << compute_min_refills(d, m, stops) << "\n";

	return 0;
}
