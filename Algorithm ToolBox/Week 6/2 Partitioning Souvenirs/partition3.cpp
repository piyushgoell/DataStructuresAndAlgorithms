#include <iostream>
#include <vector>

using std::vector;
bool check(vector<int> &A, int n, int sum)
{
  if (sum == 0)
    return true;
  if (n == 0)
    return false;
  if (A[n - 1] > sum)
    return check(A, n - 1, sum);
  return check(A, n - 1, sum) || check(A, n - 1, sum - A[n - 1]);
}

int partition3(vector<int> &A)
{
  size_t sum = 0;
  for (auto i : A)
    sum += i;
  if (sum % 3 != 0)
    return 0;
  return check(A, A.size(), sum / 3);

  return 1;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i)
  {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
