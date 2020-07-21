#include <iostream>
#include <vector>

using std::vector;

size_t lcs3(vector<int> &a, vector<int> &b, vector<int> &c)
{
  //write your code here
  const size_t m = a.size();
  const size_t n = b.size();
  const size_t o = c.size();
  vector<vector<vector<size_t>>> dp(m + 1, vector<vector<size_t>>(n + 1, vector<size_t>(o + 1, 0)));
  for (size_t i = 1; i <= m; i++)
  {
    for (size_t j = 1; j <= n; j++)
    {
      for (size_t k = 1; k <= o; k++)
      {

        if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1])
        {
          dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
        }
        else
        {
          dp[i][j][k] = std::max(std::max(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i][j][k - 1]);
        }
      }
    }
  }
  return dp[m][n][o];
}

int main()
{
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++)
  {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++)
  {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++)
  {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
