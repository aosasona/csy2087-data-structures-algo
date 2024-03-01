#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::vector;

vector<int> remove_duplicates(vector<int> vec) {
  vector<int> result = vector<int>();

  // this will only hold the ones that have been checked, the value doesn't
  // really matter, but we will use 1 so there is a value (I don't like zero
  // here, maybe bad perf, meh)
  std::unordered_map<int, int> encountered = std::unordered_map<int, int>();

  for (int i = 0; i < vec.size(); i++) {
    int value = vec.at(i);
    if (encountered.count(vec.at(i)) >= 1) {
      continue;
    }

    result.push_back(value);
    encountered[value] = 1;
  }

  return result;
}

vector<int> to_vector(int vec[], int size) {
  vector<int> output;

  for (int i = 0; i < size; i++) {
    output.push_back(vec[i]);
  }

  return output;
}

int compare(vector<int> a, vector<int> b) {
  if (a.size() != b.size()) {
    return false;
  }

  for (int i = 0; i < a.size() - 1; i++) {
    if (a[i] != b[i]) {
      return false;
    }
  }

  return true;
}

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
