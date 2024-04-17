#pragma once


// Loose ideas
class Memory {

  private:
  

  public:

  enum size{
    BYTE = 0,
    WORD = 1
  };


  void write_byte(int address, int value);
  void write_word(int address, int value);

  inline void read_byte(int address);
  inline void read_word(int address);

};