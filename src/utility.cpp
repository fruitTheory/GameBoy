#include <iostream>

void print_binary(int num){
  for(int i = 7; i >= 0; i--){
      std::cout << ((num >> i) & 1);
  } std::cout << std::endl;
}