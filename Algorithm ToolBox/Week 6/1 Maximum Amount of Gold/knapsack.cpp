#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w)
{
  //write your code here
  vector<vector<int>> dp(w.size() + 1, vector<int>(W + 1, 0));

  for (size_t i = 1; i <= w.size(); ++i)
  {
    for (size_t j = 1; j <= W; ++j){
      if (w[i - 1] > j)
      {
        dp[i][j] = dp[i - 1][j];
      }
      else
      {
        dp[i][j]= std::max(w[i-1]+dp[i-1][j-w[i-1]],dp[i-1][j]);
      }
      
    }

  }
  return dp[w.size()][W];
}

int main()
{
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++)
  {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
