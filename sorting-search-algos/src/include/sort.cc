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
