#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <vector>

using std::map;
using std::vector;
map<size_t, vector<size_t>> dp;

// vector<size_t> optimal_sequence2(size_t n)
// {
//   vector<size_t> dp{0};
//   vector<size_t> sequence;
//   if (n == 1)
//     return vector<size_t>{1};
//   for (size_t i = 2; i <= n; i++)
//   {
//     size_t op1 = INT_MAX;
//     size_t opt2 = INT_MAX;
//     size_t opt3 = INT_MAX;
//   }
// }
vector<size_t> optimal_sequence(size_t n)
{
  vector<size_t> dp(n + 1, 0);
  std::vector<size_t> sequence;
  std::vector<size_t> operations;

  for (size_t i = 1; i <= n; i++)
  {
    size_t ans1 = INT_MAX;
    size_t ans2 = INT_MAX;
    size_t ans3 = INT_MAX;

    if (i % 3 == 0)
      ans1 = dp[i / 3];
    if (i % 2 == 0)
      ans2 = dp[i / 2];
    ans3 = dp[i - 1];
    if (ans1 <= ans2 && ans1 <= ans3)
    {
      dp[i] = ans1 + 1;
      operations.push_back(3);
    }

    else if (ans2 <= ans1 && ans2 <= ans3)
    {
      dp[i] = ans2 + 1;
      operations.push_back(2);
    }

    else if (ans3 <= ans1 && ans3 <= ans2)
    {
      dp[i] = ans3 + 1;
      operations.push_back(1);
    }
  }
  while (n > 0)
  {
    sequence.push_back(n);
    if (operations[n - 1] == 1)
      n -= 1;
    else if (operations[n - 1] == 2)
      n /= 2;
    else
      n /= 3;
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main()
{
  size_t n;
  std::cin >> n;
  vector<size_t> sequence = optimal_sequence(n);
  for (auto i : dp)
  {
    std::cout << i.first << " ";
    for (auto j : i.second)
      std::cout << j << " ";
    std::cout << std::endl;
  }

  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i)
  {
    std::cout << sequence[i] << " ";
  }
}
