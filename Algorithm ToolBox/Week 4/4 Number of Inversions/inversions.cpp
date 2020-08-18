#include <iostream>
#include <vector>

using std::vector;

long long get_inversions(vector<int> &a, vector<int> &b, size_t start, size_t mid, size_t end)
{
  size_t i = start, start1 = start, start2 = mid + 1;
  long long inv_count = 0;
  while (start1 <= mid && start2 <= end)
  {
    if (a[start1] <= a[start2])
      b[i++] = a[start1++];
    else
    {
      b[i++] = a[start2++];
      inv_count += (mid - start1 + 1);
    }
  }

  while (start1 <= mid)
    b[i++] = a[start1++];

  while (start2 <= end)

    b[i++] = a[start2++];

  for (i = start; i <= end; i++)
    a[i] = b[i];

  return (long long)inv_count;
}

long long merge_sort(vector<int> &a, vector<int> &b, size_t left, size_t right)
{
  long long number_of_inversions = 0;
  if (right <= left)
    return number_of_inversions;
  size_t mid = left + ((right - left) / 2);
  number_of_inversions += merge_sort(a, b, left, mid);
  number_of_inversions += merge_sort(a, b, mid + 1, right);
  number_of_inversions += get_inversions(a, b, left, mid, right);
  return number_of_inversions;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++)
  {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << merge_sort(a, b, 0, a.size() - 1) << '\n';
}