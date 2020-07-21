#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <vector>

using std::map;
using std::vector;
map<long long, vector<long long>> dp;

// vector<long long> optimal_sequence2(long long n)
// {
//   vector<int> dp{0};
//   vector<int> sequence;
//   if (n == 1)
//     return vector<int>{1};
//   for (int i = 2; i <= n; i++)
//   {
//     int op1 = INT_MAX;
//     int opt2 = INT_MAX;
//     int opt3 = INT_MAX;
//   }
// }
vector<long long> optimal_sequence(long long n)
{
  //std::cout << n << " ";
  if (dp.count(n) != 0)
    return dp[n];
  if (n == 1)
    return vector<long long>{1};

  std::vector<long long> sequence, sequence1(n, INT_MAX), sequence2(n, INT_MAX), sequence3(n, INT_MAX);
  sequence.push_back(n);

  if (n % 3 == 0)
    sequence1 = optimal_sequence(n / 3);
  if (n % 2 == 0)
    sequence2 = optimal_sequence(n / 2);

  sequence3 = optimal_sequence(n - 1);

  if (sequence1.size() < sequence2.size() && sequence1.size() < sequence3.size())
    std::copy(sequence1.begin(), sequence1.end(), std::back_inserter(sequence));
  else if (sequence2.size() < sequence1.size() && sequence2.size() < sequence3.size())
    std::copy(sequence2.begin(), sequence2.end(), std::back_inserter(sequence));
  else
    std::copy(sequence3.begin(), sequence3.end(), std::back_inserter(sequence));

  if (dp.count(n) == 0 || dp[n].size() < sequence.size())
    dp[n] = sequence;
  return sequence;
}

int main()
{
  long long n;
  std::cin >> n;
  vector<long long> sequence = optimal_sequence(n);
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
