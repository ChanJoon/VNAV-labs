#include "random_vector.h"
#include <cmath>
#include <map>
#include <random>
#include <iostream>
#include <vector>
#include <map>
#include <limits.h>
// #include <algorithm>

RandomVector::RandomVector(int size, double max_val) {
  std::random_device r;

  // Standard mersenne_twister_engine seeded with r()
  std::mt19937 gen(r());
  std::uniform_real_distribution<double> dis(0, max_val);

  for (int i = 0; i < size; ++i){
    vect.push_back(dis(gen));
  }
}

void RandomVector::print(){
  // std::for_each(vect.begin(), vect.end(), [](const double n) { std::cout << n << ' '; });
  // for (std::vector<double>::iterator it = vect.begin(); it != vect.end(); ++it)
  for (auto &it : vect)
    std::cout << it << " ";
  std::cout << '\n';
}

double RandomVector::mean(){
  double sum;
  for (auto &it : vect) {
    sum += it;
  }
  return sum / vect.size();
}

double RandomVector::max(){
  double max = LONG_MIN;
  for (auto &it : vect) {
    if (it > max) max = it;
  }
  return max;
}

double RandomVector::min(){
  double min = LONG_MAX;
  for (auto &it : vect) {
    if (it < min) min = it;
  }
  return min;
}

void RandomVector::printHistogram(int bins){
  std::map<int, int> histogram;
  for (auto &it : vect) {
    // double norm = (it - min()) / (max() - min());
    ++histogram[std::floor(it * bins)];
  }
  int max = 0;
  for (auto &e : histogram) {
    if (e.second > max) max = e.second;
  }
  for (int i = 0; i < max; i++)
  {
    for (auto &e : histogram) {
      if (e.second >= max - i)
        std::cout << "*** ";
      else
        std::cout << "    ";
      if (e.first == histogram.size() - 1)
        std::cout << "\n";
    }
  }
}
