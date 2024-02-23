#include <cassert>
#include <cstdio>
#include <iostream>

#include "include/sort.h"
#include "include/utils.h"

struct Test {
  std::vector<int> list;
  std::vector<int> expected;
};

void task_one();

int main(int argc, char **arg_list) {
  if (argc <= 1) {
    std::printf("Usage: %s <task-number>\n", arg_list[0]);
    return 1;
  }

  int task_number = std::atoi(arg_list[1]);
  switch (task_number) {
    case 1:
      task_one();
      break;
    default:
      std::printf("Unknown task number: %d", task_number);
      return 1;
  }

  return 0;
}

void task_one() {
  std::cout << "Executing task one\n";

  int arr1[] = {7, 2, 3, 8, 9, 1};
  int r1[] = {1, 2, 3, 7, 8, 9};

  int arr2[] = {55, 22, 44, 11, 33};
  int r2[] = {11, 22, 33, 44, 55};

  int arr3[] = {101, 22, 44, 57, 45, 77};
  int r3[] = {22, 44, 45, 57, 77, 101};

  Test tests[] = {
      {.list = to_vector(arr1, 6), .expected = to_vector(r1, 6)},
      {.list = to_vector(arr2, 5), .expected = to_vector(r2, 5)},
      {.list = to_vector(arr3, 6), .expected = to_vector(r3, 6)},
  };

  for (auto &v : tests) {
    auto sorted_list = bubble_sort(v.list);
    assert(compare(sorted_list, v.expected));
  }
}
