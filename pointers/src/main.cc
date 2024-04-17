#include <cassert>
#include <cstdio>
#include <iostream>
#include <unordered_map>

#include "include/utils.h"

#define SUCCESS(msg) std::printf("\x1b[92m> [SUCCESS] %s test \x1b[0m\n", msg);
#define PRINT_TASK(tno) std::printf("Executing task \x1b[95m%d \x1b[0m\n", tno);

auto tasks = std::unordered_map<int, void (*)()>();

int main(int argc, char *arg_list[]) {
  if (argc <= 1) {
    std::printf("Usage: %s <task-number> (use 0 to run all)\n", arg_list[0]);
    return 1;
  }

  return 0;
}
