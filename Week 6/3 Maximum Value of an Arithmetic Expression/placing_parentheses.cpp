#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using std::max;
using std::min;
using std::string;
using std::vector;

long long eval(long long a, long long b, char op)
{
  if (op == '*')
  {
    return a * b;
  }
  else if (op == '+')
  {
    return a + b;
  }
  else if (op == '-')
  {
    return a - b;
  }
  else
  {
    assert(0);
  }
}

long long get_maximum_value(const string &exp)
{
  //write your code here
  long long length = exp.size() / 2;
  vector<vector<long long>> min_array(length + 1, vector<long long>(length + 1, 0));
  vector<vector<long long>> max_array(length + 1, vector<long long>(length + 1, 0));
  for (long long i = 0; i <= length; i++)
  {
    min_array[i][i] = std::stoll(exp.substr(2 * i, 1));
    max_array[i][i] = std::stoll(exp.substr(2 * i, 1));
  }

  for (long long s = 0; s < length; s++)
  {
    for (long long i = 0; i < length - s; i++)
    {
      long long j = s + i + 1;
      long long minVal = INT_MAX;
      long long maxVal = INT_MIN;

      for (long long k = i; k < j; k++)
      {
        long long a = eval(min_array[i][k], min_array[k + 1][j], exp[2 * k + 1]);
        long long b = eval(min_array[i][k], max_array[k + 1][j], exp[2 * k + 1]);
        long long c = eval(max_array[i][k], min_array[k + 1][j], exp[2 * k + 1]);
        long long d = eval(max_array[i][k], max_array[k + 1][j], exp[2 * k + 1]);

        minVal = std::min(minVal, std::min(a, std::min(b, std::min(c, d))));
        maxVal = std::max(maxVal, std::max(a, std::max(b, std::max(c, d))));
      }
      min_array[i][j] = minVal;
      max_array[i][j] = maxVal;
    }
  }

  return max_array[0][length];
}

int main()
{
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
