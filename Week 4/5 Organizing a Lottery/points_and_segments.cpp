#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using std::vector;

struct int3
{
  long long point;
  long long role;
  long long index;
};
enum type
{
  Left,
  Right,
  Point,
};

vector<long long> fast_count_segments(vector<long long> starts, vector<long long> ends, vector<long long> points)
{
  vector<long long> cnt(points.size());
  vector<int3> vec;
  for (size_t i = 0; i < starts.size(); i++)
    vec.push_back({starts[i], Left, i});
  for (size_t i = 0; i < ends.size(); i++)
    vec.push_back({ends[i], Right, i});
  for (size_t i = 0; i < points.size(); i++)
    vec.push_back({points[i], Point, i});

  std::sort(vec.begin(), vec.end(), [](const int3 &lhs, const int3 &rhs) {
    if (lhs.point == rhs.point)
      if (lhs.role == Left && rhs.role == Point)
        return true;
      else if (lhs.role == Point && rhs.role == Right)
        return true;
      else
        return false;
    else if (lhs.point < rhs.point)
      return true;
    else
      return false;
  });
  // for (auto i : vec)
  //   std::cout << i.point << " " << i.role << "\n";
  long long count = 0;
  for (auto i : vec)
  {
    if (i.role == 0)
      count++;
    if (i.role == 1)
      count--;
    if (i.role == 2)
      cnt[i.index] = count;
  }
  return cnt;
}

vector<long long> naive_count_segments(vector<long long> starts, vector<long long> ends, vector<long long> points)
{
  vector<long long> cnt(points.size());

  for (size_t i = 0; i < points.size(); i++)
  {
    for (size_t j = 0; j < starts.size(); j++)
    {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main()
{
  long long n, m;
  std::cin >> n >> m;
  vector<long long> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++)
  {
    std::cin >> starts[i] >> ends[i];
  }
  vector<long long> points(m);
  for (size_t i = 0; i < points.size(); i++)
  {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<long long> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++)
  {
    std::cout << cnt[i] << ' ';
  }
}
