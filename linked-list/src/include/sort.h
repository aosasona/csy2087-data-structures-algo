#include <vector>

// Passing by value on purpose to get the output out instead of mutating
// in-place
std::vector<int> bubble_sort(std::vector<int>);

std::vector<int> selection_sort(std::vector<int>);

std::vector<int> insertion_sort(std::vector<int>);

std::vector<int> quick_sort(std::vector<int>&);
