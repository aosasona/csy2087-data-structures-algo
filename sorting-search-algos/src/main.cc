#include <cassert>
#include <cstdio>
#include <iostream>
#include <map>

#include "include/sort.h"
#include "include/utils.h"

struct Test {
  std::vector<int> list;
  std::vector<int> expected;
};

#define SUCCESS(msg) std::printf("\x1b[92m> [SUCCESS] %s test \x1b[0m\n", msg);
#define PRINT_TASK(tno) \
  std::printf("> Executing \x1b[95mtask %d \x1b[0m\n", tno);
#define TEST(fn, tests)                       \
  for (auto &v : tests) {                     \
    auto sorted_list = fn(v.list);            \
    assert(compare(sorted_list, v.expected)); \
  }

void task_one();
void task_two();
void task_three();
void task_four();
void task_five();
void task_six();
void task_seven();

int main(int argc, char *arg_list[]) {
  if (argc <= 1) {
    std::printf("Usage: %s <task-number> (use 0 to run all)\n", arg_list[0]);
    return 1;
  }

  int task_number = std::atoi(arg_list[1]);

  std::map tasks = std::map<int, void (*)()>{
      {1, task_one},  {2, task_two}, {3, task_three}, {4, task_four},
      {5, task_five}, {6, task_six}, {7, task_seven},
  };

  if (task_number == 0) {
    for (const auto &task : tasks) {
      task.second();
    }

    return 0;
  }

  auto task = tasks.at(task_number);
  if (task == NULL) {
    std::printf("\x1b[91mUnknown task number: %d\x1b[0m\n", task_number);
    return 1;
  }

  task();
  return 0;
}

void task_one() {
  PRINT_TASK(1);

  Test tests[] = {
      {.list = {7, 2, 3, 8, 9, 1}, .expected = {1, 2, 3, 7, 8, 9}},
      {.list = {55, 22, 44, 11, 33}, .expected = {11, 22, 33, 44, 55}},
      {.list = {101, 22, 44, 57, 45, 77},
       .expected = {22, 44, 45, 57, 77, 101}},
  };

  TEST(bubble_sort, tests);

  SUCCESS("bubble sort");
}

void task_two() {
  PRINT_TASK(2);

  Test tests[] = {
      {.list = {5, 7, 2, 8, 9, 1}, .expected = {1, 2, 5, 7, 8, 9}},
      {.list = {8, 29, 19, 7, 45, 18}, .expected = {7, 8, 18, 19, 29, 45}},
      {.list = {123, 11, 2, 50, 55, 24, 34},
       .expected = {2, 11, 24, 34, 50, 55, 123}},
  };

  TEST(selection_sort, tests);

  SUCCESS("selection sort");
}

void task_three() {
  PRINT_TASK(3);

  Test tests[] = {
      {.list = {7, 2, 4, 6, 3, 1}, .expected = {1, 2, 3, 4, 6, 7}},
      {.list = {25, 12, 37, 65, 24, 17}, .expected = {12, 17, 24, 25, 37, 65}},
      {.list = {101, 27, 33, 45, 27, 68, 55},
       .expected = {27, 27, 33, 45, 55, 68, 101}},
  };

  TEST(insertion_sort, tests);

  SUCCESS("insertion sort");
}

void task_four() {
  PRINT_TASK(4);

  Test tests[] = {
      {.list = {7, 2, 4, 6, 3, 1}, .expected = {7, 2, 4, 6, 3, 1}},
      {.list = {25, 12, 37, 65, 24, 17}, .expected = {25, 12, 37, 65, 24, 17}},
  };

  for (auto &v : tests) {
    assert(compare(v.list, v.expected));
  }

  SUCCESS("Successfully ran vector comparison test");
}

void task_five() {
  PRINT_TASK(5);

  int sum = alternating_sum({1, 4, 9, 16, 9, 7, 4, 9, 11});
  assert(sum == -2);

  SUCCESS("alternating sum");
}

void task_six() {
  PRINT_TASK(6);

  vector<int> filtered_vec = remove_duplicates({1, 4, 9, 16, 9, 7, 4, 9, 11});
  assert(compare(filtered_vec, {1, 4, 9, 16, 7, 11}));

  SUCCESS("remove_duplicates");
}

void task_seven() {
  PRINT_TASK(7);

  Test tests[] = {
      {.list = {101, 27, 33, 45, 27, 68, 55},
       .expected = {27, 27, 33, 45, 55, 68, 101}},

      {.list = {101, 22, 44, 57, 45, 77},
       .expected = {22, 44, 45, 57, 77, 101}},

      {.list = {7, 2, 3, 8, 9, 1}, .expected = {1, 2, 3, 7, 8, 9}},

      {.list = {55, 22, 44, 11, 33}, .expected = {11, 22, 33, 44, 55}},
  };

  TEST(quick_sort, tests);

  SUCCESS("quick sort");
}
