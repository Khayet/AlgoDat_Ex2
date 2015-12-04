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

void swap(std::vector<int>& v, int lhs, int rhs) {
  int temp = v[lhs];
  v[lhs] = v[rhs];
  v[rhs] = temp;
}

bool quicksort(std::vector<int>& vec, int start, int end) {
  int length = end-start+1;

  if (length <= 1) return true;
  if (length == 2) {
    if (vec[start] > vec[end]) swap(vec, start, end);
    return true;
  }
  if (length == 3) {
    if (vec[start] > vec[start+1]) swap(vec, start, start+1);
    if (vec[start+1] > vec[end]) swap(vec, start+1, end);
    if (vec[start] > vec[start+1]) swap(vec, start, start+1);
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

    if (left < right) { 
      swap(vec, left, right);
      ++left;
      --right;
    }

  }

  swap(vec, start, right);
  quicksort(vec, start, right-1);
  quicksort(vec, right, end);

  return true;
}


int main(int argc, char* argv[]) {
  std::vector<int> v;

  for (int i=1; i < argc; ++i) {
    v.push_back(std::stoi(argv[i]));
  }

  print_vector(v);
  quicksort(v, 0, v.size()-1);
  print_vector(v);
  
  return 0;
}