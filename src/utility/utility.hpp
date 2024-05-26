#pragma once

#include "config.hpp"
#include <iostream>
#include <cstdint>
#include <format>

using std::array;

struct Utils{

  static void print_binary(int num);
  static void print_buffer(uint8_t* buffer, size_t size);
  static int convert_signed(int number);

  // Print vector of any type in hex
  template<typename T>
  static void print_vector(const T &vec){
    for(auto i: vec){
      std::cout << std::format("{:02X}", i) << " " ;
    } endline;
  }
  
  // Print limited vector of any type in hex
  template<typename T>
  static void print_vector_limit(const T &vec, int limit){
    int count = 0; 
    for(auto i: vec){
      ++count;
      if(count > limit){break;}
      std::cout << std::format("{:02X}", i) << " " ;
    } endline;
  }

  // Print 2D array of any type and size in hex
  template<typename T, size_t rows, size_t col>
  static void print_2D_array(const array<array< T, col>, rows> &arr){
    int inner_iter{1};
    for(auto row: arr){
      for(int i: row){
        std::cout << std::format("{:02X}", i) << " " ;
        if(inner_iter % 64 == 0){ std::cout << '\n'; }
        ++inner_iter;
      }
      std::cout << '\n';
    }
  }

  // Print limited 2D array of any type and size in hex
  template<typename T, size_t rows, size_t col>
  static void print_2D_array_limit(const array<array< T, col>, rows> &arr, int limit){
    int iter{0};
    int inner_iter{1};
    for(auto row: arr){
      for(int i: row){
        std::cout << std::format("{:02X}", i) << " " ;
        if(inner_iter % 64 == 0){ std::cout << '\n'; }
        ++inner_iter;
      }
      std::cout << '\n';
      if(iter == limit - 1){ break;}
      ++iter;
    }
  }
};