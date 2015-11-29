#include <iostream>
#include <vector>
#include <string>

template<typename T>
void print_vector(std::vector<T> const& input) {
  std::cout << "Sorted vector: " << std::endl;
  
  for (auto i : input) {
    std::cout << i << " ";    
  }

  std::cout << std::endl;
}

/*template<typename T>
void swap(T& lhs, T& rhs) {
  T temp = lhs;
  lhs = rhs;
  rhs = temp;
}*/

void swap(int lhs, int rhs) {
  int temp = lhs;
  lhs = rhs;
  rhs = temp;
}

bool quicksort(std::vector<int>& vec, int start, int end) {
  if (vec.size() < 1) return true;
  if (vec.size() == 2) {
    if (vec[start] > vec[end]) swap(vec[start], vec[end]);
    return true;
  }
  if (vec.size() == 3) {
    if (vec[start] > vec[start+1]) swap(vec[start], vec[start+1]);
    if (vec[start+1] > vec[end]) swap(vec[start+1], vec[end]);
    if (vec[start] > vec[start+1]) swap(vec[start], vec[start+1]);
    return true;
  }

  int pivot = vec[start];
  unsigned left = start + 1;
  unsigned right = end;

  while (left < right) {
    while (vec[left] < pivot) {
      ++left;
    }

    while (vec[right] >= pivot) {
      --right;
    }

    swap(vec[left], vec[right]);
  }

  swap(vec[start], vec[right]);

  quicksort(vec, start, right-1);
  quicksort(vec, right, end);

  return true;
}


int main(int argc, char* argv[]) {
  std::vector<int> v;
  
  for (int i=0; i < argc; ++i) {
    v.push_back(std::atoi(argv[i]));
  }

  quicksort(v, 0, v.size());
  print_vector(v);
  
  return 0;
}