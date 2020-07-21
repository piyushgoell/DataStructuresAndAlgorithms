#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

size_t lcs2(vector<int> &a, vector<int> &b)
{
  //write your code here
  const size_t m = a.size();
  const size_t n = b.size();
  vector<vector<size_t>> dp(m + 1, vector<size_t>(n + 1, 0));
  for (size_t i = 1; i < m + 1; i++)
  {
    for (size_t j = 1; j < n + 1; j++)
    {
      if (a[i - 1] == b[j - 1])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else
      {
        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[m][n];
}

int main()
{
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++)
  {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
