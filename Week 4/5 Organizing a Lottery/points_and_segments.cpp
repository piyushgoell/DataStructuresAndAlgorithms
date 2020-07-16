#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using std::vector;
enum type
{
  Left,
  Point,
  Right,
};
struct int3
{
  long long point;
  long long role;
  long long index;
};

vector<long long> fast_count_segments(vector<long long> starts, vector<long long> ends, vector<long long> points)
{
  vector<long long> cnt(points.size());
  vector<int3> vec;
  vec.reserve(starts.size() + ends.size() + points.size());
  for (size_t i = 0; i < starts.size(); i++)
    vec.push_back({starts[i], Left, (int)i});

  for (size_t i = 0; i < ends.size(); i++)
    vec.push_back({ends[i], Right, (int)i});

  for (size_t i = 0; i < points.size(); i++)
    vec.push_back({points[i], Point, (int)i});

  std::sort(vec.begin(), vec.end(), [](const int3 &lhs, const int3 &rhs) {
    if (lhs.point == rhs.point)
      return lhs.role < rhs.role;
    else
      return lhs.point < rhs.point;
  });
  // std::cout << "********\n";
  // for (auto i : vec)
  //   std::cout << i.point << " " << i.role << "\n";
  size_t count = 0;
  for (size_t i = 0; i < vec.size(); i++)
  {
    if (vec[i].role == Left)
      count++;
    else if (vec[i].role == Point)
      cnt[vec[i].index] = count;
    else
      count--;
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