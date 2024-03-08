#include <cstdio>
#include <vector>

#include "include/utils.h"

using namespace std;

// We are subtracting 1 from the length of the vecay/vector in most of these
// sorting functions because a lot of them check the `n + 1` and making the
// outer loop (n) the same range as the vector's size could cause an out of
// bound index when we reach the end and attend to access `n + 1`
// e.g. length is 5, valid indices are 0, 1, 2, 3, 4, when we reach 4 and
// attempt to do n+1, we can't

vector<int> bubble_sort(vector<int> vec) {
  for (int i = 0; i < vec.size() - 1; i++) {
    for (int j = 0; j < vec.size() - i - 1; j++) {
      if (vec[j] > vec[j + 1]) {
        int tmp = vec[j];
        vec[j] = vec[j + 1];
        vec[j + 1] = tmp;
      }
    }
  }

  return vec;
}

vector<int> selection_sort(vector<int> vec) {
  int i, j;
  int len = vec.size();

  for (i = 0; i < len - 1; i++) {
    int min_value = vec[i];
    int min_idx = i;

    for (j = i + 1; j < len; j++) {
      if (vec[j] < min_value) {
        min_value = vec[j];
        min_idx = j;
      }
    }

    vec[min_idx] = vec[i];
    vec[i] = min_value;
  }

  return vec;
}

vector<int> insertion_sort(vector<int> vec) {
  for (int i = 0; i < vec.size(); i++) {
    int j = i;
    int start_val = vec[i];

    while (j > 0 && vec[j - 1] > vec[j]) {
      int temp = vec[j];
      vec[j] = vec[j - 1];
      vec[j - 1] = temp;

      j--;
    }
  }

  return vec;
}

vector<int> quick_sort(vector<int>& vec) {
  if (vec.size() <= 1) {
    return vec;
  }

  int pivot = vec[0];
  vec.erase(vec.begin());

  vector<int> l_arr = vector<int>();
  vector<int> r_arr = vector<int>();

  for (const int item : vec) {
    if (pivot >= item) {
      l_arr.push_back(item);
    } else {
      r_arr.push_back(item);
    }
  }

  auto l = quick_sort(l_arr);
  auto r = quick_sort(r_arr);

  l.push_back(pivot);
  if (r.size() > 0) {
    l.insert(end(l), begin(r), end(r));
  }

  return l;
}
