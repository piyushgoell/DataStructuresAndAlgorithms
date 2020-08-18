#include <algorithm>
#include <iostream>
#include <string>

using std::string;

size_t edit_distance(const string &str1, const string &str2)
{
  const size_t m = str1.size();
  const size_t n = str2.size();
  size_t dp[m + 1][n + 1] = {0};
  for (size_t i = 0; i <= m; i++)
    dp[i][0] = i;
  for (size_t i = 0; i <= n; i++)
    dp[0][i] = i;
  for (size_t i = 1; i <= m; i++)
  {
    for (size_t j = 1; j <= n; j++)
    {
      if (str1[i - 1] == str2[j - 1])
        dp[i][j] = dp[i - 1][j - 1];
      else
        dp[i][j] = 1 + std::min(std::min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]);
    }
  }
  return dp[m][n];
  return 0;
}

int main()
{
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
