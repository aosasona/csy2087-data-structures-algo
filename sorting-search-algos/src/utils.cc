#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::vector;

int alternating_sum(vector<int> vec) {
  int result = 0;
  // should subtract, then add
  for (int i = 0; i < vec.size(); i++) {
    if ((i + 1) % 2 == 0) {
      result -= vec[i];
    } else {
      result += vec[i];
    }
  }
  return result;
}

vector<int> remove_duplicates(vector<int> vec) {
  vector<int> result = vector<int>();

  // this will only hold the ones that have been checked, the value doesn't
  // really matter, but we will use 1 so there is a value (I don't like zero
  // here, maybe bad perf, meh)
  auto encountered = std::unordered_map<int, int>();

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

vector<int> to_vector(int arr[], int size) { return vector(arr, arr + size); }

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
    output += std::to_string(vec[i]);
    output += ", ";
  }

  output.pop_back();
  output.pop_back();

  output += "]\n";
  std::cout << output;
}

void dump(std::string name, vector<int> vec) {
  std::printf("%s: ", name.c_str());
  dump(vec);
}
