#include <cassert>
#include <cstdio>
#include <iostream>

#include "include/sort.h"
#include "include/utils.h"

struct Test {
  std::vector<int> list;
  std::vector<int> expected;
};

#define SUCCESS(msg) std::printf("\x1b[92m[SUCCESS] %s \x1b[0m\n", msg);
#define PRINT_TASK(tno) \
  std::printf("\x1b[94m> Executing task %d \x1b[0m\n", tno);

void task_one();
void task_two();
void task_three();

int main(int argc, char *arg_list[]) {
  if (argc <= 1) {
    std::printf("Usage: %s <task-number>\n", arg_list[0]);
    return 1;
  }

  int task_number = std::atoi(arg_list[1]);
  int fallthrough = task_number == 0 ? 1 : 0;

  switch (task_number) {
    case 0:
    case 1:
      task_one();
      if (!fallthrough) break;
    case 2:
      task_two();
      if (!fallthrough) break;
    case 3:
      task_three();
      break;
    default:
      std::printf("\x1b[91mUnknown task number: %d\x1b[0m\n", task_number);
      return 1;
  }

  return 0;
}

void task_one() {
  PRINT_TASK(1);

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

  SUCCESS("Successfully ran bubble sort test");
}

void task_two() {
  PRINT_TASK(2);

  int a1[] = {5, 7, 2, 8, 9, 1};
  int r1[] = {1, 2, 5, 7, 8, 9};

  int a2[] = {8, 29, 19, 7, 45, 18};
  int r2[] = {7, 8, 18, 19, 29, 45};

  int a3[] = {123, 11, 2, 50, 55, 24, 34};
  int r3[] = {2, 11, 24, 34, 50, 55, 123};

  Test tests[] = {
      {.list = to_vector(a1, 6), .expected = to_vector(r1, 6)},
      {.list = to_vector(a2, 6), .expected = to_vector(r2, 6)},
      {.list = to_vector(a3, 7), .expected = to_vector(r3, 7)},
  };

  for (auto &v : tests) {
    auto sorted_list = selection_sort(v.list);
    assert(compare(sorted_list, v.expected));
  }

  SUCCESS("Successfully ran selection sort test");
}

void task_three() {
  PRINT_TASK(3);

  int a1[] = {7, 2, 4, 6, 3, 1};
  int r1[] = {1, 2, 3, 4, 6, 7};

  int a2[] = {25, 12, 37, 65, 24, 17};
  int r2[] = {12, 17, 24, 25, 37, 65};

  int a3[] = {101, 27, 33, 45, 27, 68, 55};
  int r3[] = {27, 27, 33, 45, 55, 68, 101};

  Test tests[] = {
      {.list = to_vector(a1, 6), .expected = to_vector(r1, 6)},
      {.list = to_vector(a2, 6), .expected = to_vector(r2, 6)},
      {.list = to_vector(a3, 7), .expected = to_vector(r3, 7)},
  };

  for (auto &v : tests) {
    auto sorted_list = insertion_sort(v.list);
    assert(compare(sorted_list, v.expected));
  }

  SUCCESS("Successfully ran insertion sort test");
}
