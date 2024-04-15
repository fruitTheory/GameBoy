#pragma once

#include <iostream>
#include <vector>
#include "config.hpp"

struct Utils{

  static void print_binary(int num);

  template<typename T>
  static void print_vector(std::vector<T> vec){
    for(T i = 0; i < vec.size(); i++){
      std::cout << vec[i];
    } endline;
  }

};