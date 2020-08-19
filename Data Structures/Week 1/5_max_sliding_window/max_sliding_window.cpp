#include <deque>
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::max;
using std::vector;

void max_sliding_window_naive(vector<int> const &A, int w)
{
    std::deque<int> dq(w);
    for (size_t i = 0; i < w; ++i)
    {
        while (!dq.empty() && A[i] >= A[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    for (int i = w; i < A.size(); ++i)
    {
        cout << A[dq.front()] << " ";
        while (!dq.empty() && dq.front() <= i - w)
            dq.pop_front();

        while (!dq.empty() && A[i] >= A[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    cout << A[dq.front()];
}

int main()
{
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window_naive(A, w);

    return 0;
}
