#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::min;
using std::pair;
using std::string;
using std::vector;

double get_distance(vector<pair<long, long>> xy)
{
  return sqrt((double)(pow(xy[1].first - xy[0].first, 2) + (double)pow(xy[1].second - xy[0].second, 2)));
}

double calculate(vector<std::pair<size_t, size_t>> &xy, size_t left, size_t right)
{
  //Base Condition: for one point
  // can't calculate distance of one point
  if (left == right)
    return 9999999999999.9;

  // Base Condition : for two points
  // calculate the distance between two points
  if (right - left == 1)
    return get_distance({xy[left], xy[right]});

  if (right - left == 2)
    return min(min(get_distance({xy[left], xy[left + 1]}), get_distance({xy[left], xy[right]})), get_distance({xy[left + 1], xy[right]}));
  // find the middle value
  size_t mid = left + (right - left) / 2;

  //std::cout << left << " " << right << " " << mid << "\n";

  //  Split the array into two parts and calculate the distance
  double d1 = calculate(xy, left, mid);
  double d2 = calculate(xy, mid, right);
  // find the minimum distance of two calculated distances
  double d = min(d1, d2);

  // now sort the above array based on Y
  std::sort(xy.begin() + left, xy.begin() + right, [](const std::pair<size_t, size_t> &lhs, const std::pair<size_t, size_t> &rhs) {
    return lhs.second < rhs.second;
  });
  // Grab the points lying on the section mid +- d and store them into seperate array
  vector<std::pair<size_t, size_t>> points;
  //size_t line = xy[left].first + (xy[right].first - xy[left].first) / 2;
  double line = (xy[left].first + xy[right].second) / 2;
  for (size_t i = left; i <= right; i++)
    if (abs(xy[i].first - line) < d) //Check the condition abs works for +-
      points.push_back(xy[i]);

  // Now split the section mid +- d into d distance blocks and find the pair of points inside these d blocks
  // whose distance is less than d;
  for (size_t i = 0; i < points.size(); i++)
    for (size_t j = i + 1; j <= min(i + 9, points.size()); j++)
      if (points[j].second - points[i].second < d)
        d = min(d, get_distance({xy[i], xy[j]}));

  return d;
}

double minimal_distance(vector<size_t> x, vector<size_t> y)
{
  // Combining the x and y points
  vector<std::pair<size_t, size_t>> xy;
  std::transform(x.begin(), x.end(), y.begin(), std::back_inserter(xy), [](size_t a, size_t b) { return std::make_pair(a, b); });

  // sorting the points based on X value
  sort(xy.begin(), xy.end(), [](const std::pair<size_t, size_t> &lhs, const std::pair<size_t, size_t> &rhs) {
    return lhs.first < rhs.first;
  });

  // for (size_t i = 0; i < xy.size(); i++)
  //   std::cout << xy[i].first << " ";
  // std::cout << "\n";
  return calculate(xy, 0, xy.size() - 1);
}

int main()
{
  size_t n;
  std::cin >> n;
  vector<size_t> x(n);
  vector<size_t> y(n);
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(x, y) << "\n";
}
