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

double get_distance(vector<pair<int, int>> xy)
{
  return sqrt((double)(pow(xy[1].first - xy[0].first, 2) + (double)pow(xy[1].second - xy[0].second, 2)));
}

double bruteForce(vector<std::pair<int, int>> &xy, size_t left, size_t right)
{
  double min = INT_MAX;
  for (size_t i = left; i <= right; i++)
  {
    for (size_t j = i + 1; j <= right; j++)
    {
      double distance = get_distance(vector<std::pair<int, int>>({xy[i], xy[j]}));
      if (distance < min)
        min = distance;
    }
  }
  return min;
}
double calculate(vector<std::pair<int, int>> &xy, size_t left, size_t right)
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

  //  Split the array into two parts and calculate the distance
  double d1 = calculate(xy, left, mid);
  double d2 = calculate(xy, mid + 1, right);
  // find the minimum distance of two calculated distances
  double d = min(d1, d2);

  // Grab the points lying on the section mid +- d and store them into seperate array
  vector<std::pair<int, int>> points;
  for (size_t i = left; i <= right; i++)
    if ((xy[i].first >= xy[mid].first - d) && (xy[i].first <= xy[mid].first + d)) //Check the condition abs works for +-
      points.push_back(xy[i]);

  // now sort the above array based on Y
  std::sort(points.begin(), points.begin(), [](const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) {
    return lhs.second < rhs.second;
  });

  // Now split the section mid +- d into d distance blocks and find the pair of points inside these d blocks
  // whose distance is less than d;
  for (size_t i = 0; i < points.size(); i++)
  {
    for (size_t j = i + 1; j < points.size() && abs(points[j].second - points[i].second) <= d; j++)
    {
      double distance = get_distance({xy[i], xy[j]});
      if (distance < d)
        d = distance;
    }
  }
  return d;
}

double minimal_distance(vector<int> x, vector<int> y)
{
  // Combining the x and y points
  vector<std::pair<int, int>> xy;
  std::transform(x.begin(), x.end(), y.begin(), std::back_inserter(xy), [](int a, int b) { return std::make_pair(a, b); });

  // sorting the points based on X value
  sort(xy.begin(), xy.end(), [](const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) {
    return lhs.first < rhs.first;
  });

  return calculate(xy, 0, x.size() - 1);
}

int main()
{
  size_t n;
  std::cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(x, y) << "\n";
}
