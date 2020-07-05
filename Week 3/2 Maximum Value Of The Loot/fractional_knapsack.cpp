#include <iostream>
#include <vector>
#include <utility> 
#include<algorithm>


using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
	double value = 0.0;

	vector<std::pair<int, int>> vec;
	for (int i = 0; i < weights.size(); i++)
		vec.push_back(std::make_pair(values[i], weights[i]));

	sort(vec.begin(), vec.end(), [](const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) {
		return (double)lhs.first / lhs.second > (double)rhs.first / rhs.second;
		});

	for (int i = 0; i < vec.size(); i++) {
		if (capacity == 0)
			return value;
		else if (vec[i].second <= capacity) {
			capacity -= vec[i].second;
			value += vec[i].first;
		}
		else {
			value += (capacity * double(vec[i].first) / vec[i].second) ;
			return value;
		}
	}

	return value;
}

int main() {
	int n;
	int capacity;
	std::cin >> n >> capacity;
	vector<int> values(n);
	vector<int> weights(n);
	for (int i = 0; i < n; i++) {
		std::cin >> values[i] >> weights[i];
	}

	double optimal_value = get_optimal_value(capacity, weights, values);

	std::cout.precision(4);
	std::cout<<std::fixed;
	std::cout << optimal_value << std::endl;
	return 0;
}
