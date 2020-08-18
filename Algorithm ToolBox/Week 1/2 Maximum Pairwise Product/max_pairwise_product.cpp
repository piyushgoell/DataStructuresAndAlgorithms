#include <iostream>
#include <vector>
#include <algorithm>

int MaxPairwiseProduct(const std::vector<int>& numbers) {
    int max_product = 0;
    int n = numbers.size();
	int Max_Index1 = 0, Max_Index2=0;
    for (int i = 0; i < n; ++i) {
    	if(numbers[i]>numbers[Max_Index1]){
    		Max_Index2 = Max_Index1;
			Max_Index1 = i;
		}
    	if(i != Max_Index1 && numbers[i]>numbers[Max_Index2])
			Max_Index2 = i;
	}
    return ((long long)(numbers[Max_Index1]))* numbers[Max_Index2];
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
