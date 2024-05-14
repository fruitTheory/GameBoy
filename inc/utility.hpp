#pragma once

#include "config.hpp"
#include <iostream>
#include <cstdint>
#include <format>

struct Utils{

  static void print_binary(int num);
  static void print_buffer(uint8_t* buffer, size_t size);
  static int convert_signed(int number);

  // Print vector of any type in hex
  template<typename T>
  static void print_vector(const T &vec){
    for(const auto i: vec){
      std::cout << std::format("{:02X}", i) << " " ;
    } endline;
  }
  // Print vector of any type in hex
  template<typename T>
  static void print_vector_limit(const T &vec, int limit){
    int count = 0; 
    for(const auto i: vec){
      ++count;
      if(count > limit){break;}
      std::cout << std::format("{:02X}", i) << " " ;
    } endline;
  }
};