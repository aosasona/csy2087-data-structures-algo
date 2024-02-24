#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using std::vector;

vector<int> to_vector(int arr[], int size) {
  vector<int> output;

  for (int i = 0; i < size; i++) {
    output.push_back(arr[i]);
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

void dump(vector<int> arr) {
  std::string output;

  for (int i = 0; i < arr.size(); i++) {
    output.append(std::to_string(arr[i]));
    output.append("\n");
  }

  std::cout << output;
}
