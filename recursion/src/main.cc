#include <cassert>
#include <cstdio>
#include <iostream>
#include <map>
#include <tuple>

#include "include/impl.hh"
#include "include/utils.hh"

#define SUCCESS(msg) \
  std::printf("\x1b[92m> [SUCCESS] `%s` test \x1b[0m\n", msg);
#define PRINT_TASK(tno) \
  std::printf("> Executing \x1b[95mtask %d \x1b[0m\n", tno);
#define TEST(fn, tests)                       \
  for (auto &v : tests) {                     \
    auto sorted_list = fn(v.list);            \
    assert(compare(sorted_list, v.expected)); \
  }

struct Test {
  std::vector<int> list;
  std::vector<int> expected;
};

void task_one();
void task_two();

int main(int argc, char *arg_list[]) {
  if (argc <= 1) {
    std::printf("Usage: %s <task-number> (use 0 to run all)\n", arg_list[0]);
    return 1;
  }

  int task_number = std::atoi(arg_list[1]);

  auto tasks = std::map<int, void (*)()>{{1, task_one}, {2, task_two}};

  if (task_number == 0) {
    for (const auto &task : tasks) {
      task.second();
    }

    return 0;
  }

  auto task = tasks[task_number];
  if (task == NULL) {
    std::printf("\x1b[91m[ERROR] Unknown task number: %d\x1b[0m\n",
                task_number);
    return 1;
  }

  task();
  return 0;
}

void task_one() {
  std::tuple<int, int> tests[] = {{5, 15}, {10, 55}};

  for (std::tuple<int, int> test : tests) {
    const auto [range, expected] = test;
    auto sum = range_sum(range);
    assert(sum == expected);
  }

  SUCCESS("range_sum");
}

void task_two() {
  std::tuple<int, int, int> tests[] = {{5, 2, 25}, {10, 3, 1000}};

  for (std::tuple<int, int, int> test : tests) {
    const auto [number, power, expected] = test;
    auto result = exponent(number, power);
    assert(result == expected);
  }

  SUCCESS("exponent");
}
