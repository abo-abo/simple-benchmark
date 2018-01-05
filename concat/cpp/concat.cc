#include <iostream>
#include <vector>
#include <chrono>
#include <numeric>
#include <cstdint>
#include "printers.h"
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;

template <typename T>
std::vector<T> operator += (std::vector<T>& a, const std::vector<T>& b) {
  a.insert(a.end(), b.begin(), b.end());
  return a;
}

void check_shared_structure() {
  std::vector<int64_t> a = {1, 2, 3};
  std::vector<int64_t> b = {4, 5, 6};
  TRACE(a);
  TRACE(b);
  // a is mutated, no structure is shared
  a += b;
  TRACE(a);
  TRACE(b);
  b[2] = 7;
  TRACE(a);
  TRACE(b);
}

high_resolution_clock::time_point tic_start;
void tic() {
  tic_start = high_resolution_clock::now();
}

// return milliseconds since tic()
void toc() {
  high_resolution_clock::time_point tic_end = high_resolution_clock::now();
  int duration = duration_cast<std::chrono::microseconds>(tic_end - tic_start).count();
  std::cout << int(duration/1000.0) << "ms\n";
}

void big_concat() {
  std::vector<int64_t> a(1e7);
  std::iota(a.begin(), a.end(), 0);
  std::vector<int64_t> b = a;
  tic();
  a += b;
  toc();
  TRACE(a.size());
  tic();
  int64_t sum = std::accumulate(a.begin(), a.end(), int64_t(0));
  toc();
  TRACE(sum);
}

int main(int argc, char *argv[]) {
  std::cout << "C++:\n";
  // check_shared_structure();
  big_concat();
  return 0;
}
