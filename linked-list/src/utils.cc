#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::vector;

void dump(vector<int> vec) {
  std::string output = "[";

  for (int i = 0; i < vec.size(); i++) {
    output.append(std::to_string(vec[i]));
    output.append(", ");
  }

  // remove the last comma <space>
  output.replace(output.size() - 2, 2, "");

  output.append("]\n");

  std::cout << output;
}
