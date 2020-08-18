#include <cstdlib>
#include <iostream>
#include <vector>

using std::swap;
using std::vector;

vector<int> partitionThreeWay(vector<int> &a, int l, int r)
{
  int pivot = a[r];
  int i = l;
  int indexLow = l;
  int indexHigh = r;
  while (i <= indexHigh)
  {
    if (a[i] < pivot)
      swap(a[i++], a[indexLow++]);
    else if (a[i] > pivot)
      swap(a[i], a[indexHigh--]);
    else
      i++;
  }
  return vector<int>{indexLow, indexHigh};
}

void randomized_quick_sort(vector<int> &a, int l, int r)
{
  if (l >= r)
    return;

  int k = l + rand() % (r - l + 1);
  swap(a[r], a[k]);
  vector<int> m = partitionThreeWay(a, l, r);
  randomized_quick_sort(a, l, m[0] - 1);
  randomized_quick_sort(a, m[1] + 1, r);
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
  randomized_quick_sort(a, 0, (int)a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cout << a[i] << ' ';
  }
  return 0;
}
