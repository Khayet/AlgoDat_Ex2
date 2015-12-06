#include <memory> //std::make_shared
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

bool is_int(std::string str) {
  int num;
  std::stringstream ss(str);
  ss >> num;
  if (ss.fail()) {
    return false;
  }
  return true;
}

template<typename T>
bool quicksort(std::vector<T>& vec, int start, int end) {
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

  T pivot = vec[start];
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

  //use first element to determine type of command line arguments
  if (is_int(argv[1])) {    
    auto v = std::make_shared<std::vector<int>>();
    //start from i=1, because i=0 is the name of the program 
    for (int i=1; i < argc; ++i) {
      v->push_back(std::stoi(argv[i]));
    }
    print_vector(*v);
    quicksort(*v, 0, v->size()-1);
    print_vector(*v);
  } else if (is_double(argv[1])) {
    auto v = std::make_shared<std::vector<double>>();
    for (int i=1; i < argc; ++i) {
      v->push_back(std::stod(argv[i]));
    }
    print_vector(*v);
    quicksort(*v, 0, v->size()-1);
    print_vector(*v);
  } else {
    auto v = std::make_shared<std::vector<std::string>>();
    for (int i=1; i < argc; ++i) {
      v->push_back(argv[i]);
    }
    print_vector(*v);
    quicksort(*v, 0, v->size()-1);
    print_vector(*v);
  }

  return 0;
}