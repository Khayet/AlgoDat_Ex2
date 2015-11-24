#include <iostream>
#include <list>
#include <string>
#include <algorithm> //test-purposes

template<typename T>
void print_list(std::list<T> const& input) {
  std::cout << "Sorted list: " << std::endl;
  
  for (auto i : input) {
    std::cout << i << " ";    
  }

  std::cout << std::endl;
}

void quicksort(std::list<int>& li) {

}

int main(int argc, char* argv[]) {
  std::list<int> li;
  
  for (int i=0; i < argc; ++i) {
    li.push_back(std::atoi(argv[i]));
  }

  quicksort(li);
  print_list(li);
  
  return 0;
}