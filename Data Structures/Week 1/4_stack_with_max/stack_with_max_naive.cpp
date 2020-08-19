#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

using std::cin;
using std::string;
using std::vector;
using std::cout;
using std::max_element;

class StackWithMax {
    vector<int> stack;
    int maxValue;

public:

    void Push(int value) {
        if(stack.empty())
        {
            maxValue = value;
            stack.push_back(value);
        }
        if(value > maxValue)
        {
            stack.push_back(2 * value - maxValue);
            maxValue = value;
        }
        else
            stack.push_back(value);
        }

    void Pop() {
        assert(stack.size());
        int t = stack.back();
        stack.pop_back();
        if(t>maxValue)
            maxValue = 2 * maxValue - t;
    }

    int Max() const {
        assert(stack.size());
        return maxValue;
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.Push(std::stoi(value));
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            cout << stack.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}