#pragma once


inline float shade[4]{0, 0.33f, 0.66f, 1};
enum col { BLACK, DARK_GREY, GREY, WHITE };

class PPU {
  public:
  int temp=1;
};

void get_tile();


/*
First we'll develop reading patterns into a buffer
8x8 patterns are defined by 16 bytes, and are grouped
in two's - each two groups of bytes are compared against
each other and the parallel bits combine to make a number
between 0-3, which determine which shade of grey it receieves
*/