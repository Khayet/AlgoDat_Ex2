#include <iostream>
#include <list>
#include <string>

template<typename T>
void print_list(std::list<T> const& my_list) {
  std::cout << "Sorted list: " << std::endl;
  
  for (auto i : my_list) {
    std::cout << i << " ";    
  }

  std::cout << std::endl;
}

void quicksort(std::list<std::string>& vec) {
  
}

int main(int argc, char* argv[]) {
  std::list<std::string> my_list;
  
  for (int i=0; i < argc; ++i) {
    my_list.push_back(argv[i]);
  }

  print_list(my_list);
  
  return 0;
}