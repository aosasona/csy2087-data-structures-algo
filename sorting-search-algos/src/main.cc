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
  int fallthrough = task_number == 0 ? 1 : 0;

  std::map tasks = std::map<int, void (*)()>();
  tasks[1] = task_one;
  tasks[2] = task_two;
  tasks[3] = task_three;
  tasks[4] = task_four;
  tasks[5] = task_five;
  tasks[6] = task_six;
  tasks[7] = task_seven;

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

  vector a1 = {7, 2, 3, 8, 9, 1};
  vector r1 = {1, 2, 3, 7, 8, 9};

  vector a2 = {55, 22, 44, 11, 33};
  vector r2 = {11, 22, 33, 44, 55};

  vector a3 = {101, 22, 44, 57, 45, 77};
  vector r3 = {22, 44, 45, 57, 77, 101};

  Test tests[] = {
      {.list = a1, .expected = r1},
      {.list = a2, .expected = r2},
      {.list = a3, .expected = r3},
  };

  for (auto &v : tests) {
    auto sorted_list = bubble_sort(v.list);
    assert(compare(sorted_list, v.expected));
  }

  SUCCESS("bubble sort");
}

void task_two() {
  PRINT_TASK(2);

  vector a1 = {5, 7, 2, 8, 9, 1};
  vector r1 = {1, 2, 5, 7, 8, 9};

  vector a2 = {8, 29, 19, 7, 45, 18};
  vector r2 = {7, 8, 18, 19, 29, 45};

  vector a3 = {123, 11, 2, 50, 55, 24, 34};
  vector r3 = {2, 11, 24, 34, 50, 55, 123};

  Test tests[] = {
      {.list = a1, .expected = r1},
      {.list = a2, .expected = r2},
      {.list = a3, .expected = r3},
  };

  for (auto &v : tests) {
    auto sorted_list = selection_sort(v.list);
    assert(compare(sorted_list, v.expected));
  }

  SUCCESS("selection sort");
}

void task_three() {
  PRINT_TASK(3);

  vector a1 = {7, 2, 4, 6, 3, 1};
  vector r1 = {1, 2, 3, 4, 6, 7};

  vector a2 = {25, 12, 37, 65, 24, 17};
  vector r2 = {12, 17, 24, 25, 37, 65};

  vector a3 = {101, 27, 33, 45, 27, 68, 55};
  vector r3 = {27, 27, 33, 45, 55, 68, 101};

  Test tests[] = {
      {.list = a1, .expected = r1},
      {.list = a2, .expected = r2},
      {.list = a3, .expected = r3},
  };

  for (auto &v : tests) {
    auto sorted_list = insertion_sort(v.list);
    assert(compare(sorted_list, v.expected));
  }

  SUCCESS("insertion sort");
}

void task_four() {
  PRINT_TASK(4);

  vector a1 = {7, 2, 4, 6, 3, 1};
  vector r1 = {7, 2, 4, 6, 3, 1};

  vector a2 = {25, 12, 37, 65, 24, 17};
  vector r2 = {25, 12, 37, 65, 24, 17};

  Test tests[] = {
      {.list = a1, .expected = r1},
      {.list = a2, .expected = r2},
  };

  for (auto &v : tests) {
    assert(compare(v.list, v.expected));
  }

  SUCCESS("Successfully ran vector comparison test");
}

void task_five() {
  PRINT_TASK(5);

  vector vec = {1, 4, 9, 16, 9, 7, 4, 9, 11};
  int sum = alternating_sum(vec);
  assert(sum == -2);

  SUCCESS("alternating sum");
}

void task_six() {
  PRINT_TASK(6);

  vector vec = {1, 4, 9, 16, 9, 7, 4, 9, 11};
  vector<int> filtered_vec = remove_duplicates(vec);

  vector expected = {1, 4, 9, 16, 7, 11};
  assert(compare(filtered_vec, expected));

  SUCCESS("remove_duplicates");
}

void task_seven() {
  PRINT_TASK(7);

  vector a1 = {101, 27, 33, 45, 27, 68, 55};
  vector r1 = {27, 27, 33, 45, 55, 68, 101};

  vector a2 = {7, 2, 3, 8, 9, 1};
  vector r2 = {1, 2, 3, 7, 8, 9};

  vector a3 = {55, 22, 44, 11, 33};
  vector r3 = {11, 22, 33, 44, 55};

  vector a4 = {101, 22, 44, 57, 45, 77};
  vector r4 = {22, 44, 45, 57, 77, 101};

  Test tests[] = {
      {.list = a1, .expected = r1},
      {.list = a2, .expected = r2},
      {.list = a3, .expected = r3},
      {.list = a4, .expected = r4},
  };

  for (auto &v : tests) {
    auto sorted_list = quick_sort(v.list);
    assert(compare(sorted_list, v.expected));
  }

  SUCCESS("quick sort");
}
