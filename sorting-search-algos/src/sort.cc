#include <vector>

std::vector<int> bubble_sort(std::vector<int> arr) {
  int i = 0, j;

  for (; i < arr.size() - 1; i++) {
    for (j = 0; j < arr.size() - i - 1; j++) {
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
