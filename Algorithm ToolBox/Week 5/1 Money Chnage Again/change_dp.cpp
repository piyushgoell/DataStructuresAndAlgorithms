#include <climits>
#include <iostream>

int get_change(int m)
{
  //write your code here
  int coins[] = {1, 3, 4};
  int dp[m] = {0};
  for (int i = 1; i <= m; i++)
  {
    dp[i] = INT_MAX;
    for (int j = 0; j < sizeof(coins) / sizeof(coins[0]); j++)
    {
      if (i - coins[j] >= 0)
      {
        int sub = dp[i - coins[j]] + 1;
        dp[i] = std::min(dp[i], sub);
      }
    }
  }
  return dp[m];
}

int main()
{
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
