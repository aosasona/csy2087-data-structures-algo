#include <cstdio>
#include <vector>

// We are subtracting 1 from the length of the array/vector in most of these
// sorting functions because a lot of them check the `n + 1` and making the
// outer loop (n) the same range as the vector's size could cause an out of
// bound index when we reach the end and attend to access `n + 1`
// e.g. length is 5, valid indices are 0, 1, 2, 3, 4, when we reach 4 and
// attempt to do n+1, we can't

std::vector<int> bubble_sort(std::vector<int> arr) {
  for (int i = 0; i < arr.size() - 1; i++) {
    for (int j = 0; j < arr.size() - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
      }
    }
  }

  return arr;
}

std::vector<int> selection_sort(std::vector<int> arr) {
  int i, j;
  int len = arr.size();

  for (i = 0; i < len - 1; i++) {
    int min_value = arr[i];
    int min_idx = i;

    for (j = i + 1; j < len; j++) {
      if (arr[j] < min_value) {
        min_value = arr[j];
        min_idx = j;
      }
    }

    arr[min_idx] = arr[i];
    arr[i] = min_value;
  }

  return arr;
}

std::vector<int> insertion_sort(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    int j = i;
    int start_val = arr[i];

    while (j > 0 && arr[j - 1] > arr[j]) {
      int temp = arr[j];
      arr[j] = arr[j - 1];
      arr[j - 1] = temp;

      j--;
    }
  }

  return arr;
}
