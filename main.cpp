// Uses first command line argument to determine type of input (double, int, characters),
// sorts with quicksort and returns the sorted list.

// ! Does not work on all inputs !
// I have seen wrongly sorted lists and Segmentation Faults, but I couldn't find the problem. :(


#include <iostream>
#include <vector>
#include <string>
#include <sstream> //std::stringstream

template<typename T>
void print_vector(std::vector<T> const& input) {
  std::cout << "Sorted vector: " << std::endl;

  for (auto i : input) {
    std::cout << i << " ";
  }

  std::cout << std::endl;
}

template<typename T>
void swap(std::vector<T>& v, int lhs, int rhs) {
  T temp = v[lhs];
  v[lhs] = v[rhs];
  v[rhs] = temp;
}

bool is_double(std::string str) {
  double num;
  std::stringstream ss(str);
  ss >> num;
  if (ss.fail()) {
    return false;
  }
  return true;
}

template<typename T>
bool quicksort(std::vector<T>& vec, int start, int end) {
  if (end == start) return true;

  int left = start;
  int right = end;
  T pivot = vec[(start+end)/2];

  while (left < right) {
    while (vec[left] <= pivot) {
      left++;
    }

    while (vec[right] > pivot) {
      right--;
    }

    if (left <= right) {
      swap(vec, left, right);
      ++left;
      --right;
    }
  }

  if (start < right) quicksort(vec, start, right);
  if (left < end) quicksort(vec, left, end);

  return true;
}

int main(int argc, char* argv[]) {
  std::vector<double> vec_d;
  std::vector<int> vec_i;
  std::vector<char> vec_c;

  //use argv[1] to determine type of arguments
  if (is_double(argv[1])) {
    for (int i=1; i < argc; ++i) {
      vec_d.push_back(std::stod(argv[i]));
    }
    quicksort(vec_d, 0, vec_d.size()-1);
    print_vector(vec_d);
  } else {
    for (int i=1; i < argc; ++i) {
      for (int j=0; argv[i][j] != '\0'; ++j) {
        vec_c.push_back(argv[i][j]);
      }
    }
    quicksort(vec_c, 0, vec_c.size()-1);
    print_vector(vec_c);
  }

  return 0;
}
