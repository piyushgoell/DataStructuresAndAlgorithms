#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right)
{
  if (left == right)
    return -1;
  if (left + 1 == right)
    return a[left];
  //write your code here
  std::sort(a.begin(), a.end());
  int mid = left + (right - left) / 2;

  for (int i = 0; i <= mid; i++)
  {
    if (a[i] == a[mid + i])
      return 1;
  }

  return -1;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, (int)a.size()) != -1) << '\n';
}
