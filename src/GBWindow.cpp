#include "GBWindow.hpp"
#include "raylib.h"
#include "ppu.hpp"
#include "utility.hpp"
#include <iostream>
#include <cstdint>
#include <vector>

using std::vector;

// More C based syntax, raylib created window
void GB::Window::Create(){

  SetTraceLogLevel(LOG_ERROR);
  // Initialization
  const int screenWidth = 400;
  const int screenHeight = 400;
  InitWindow(screenWidth, screenHeight, "Title");
  SetTargetFPS(60);
  vector<int> pattern = get_tile();

  while(!WindowShouldClose()){
    BeginDrawing();

    ClearBackground(GRAY);
    DrawText("Hello World!", 150, 180, 20, LIGHTGRAY);
    DrawFPS(10, 10);
    DrawPattern(pattern);

    EndDrawing();
  }
  CloseWindow(); 
}

// Draw pixels based on a pattern
void GB::Window::DrawPattern(vector<int>pattern){

  Color Ci; // Result color
  uint8_t pixel_value = 100; // Default value/color
  int pixel_size = 5; // Default size
  uint8_t alpha = 255; // Default Alpha

  for(int pixel : pattern){
    
    static int x, y = 0;
    static int inc_x, inc_y = 0;

    // Pixel represents the palette value
    switch(pixel){
      case 0:
        pixel_value = palette[0];
        break;
      case 1:
        pixel_value = palette[1];
        break;
      case 2:
        pixel_value = palette[2];
        break;
      case 3:
        pixel_value = palette[3];
        break;
    }

    // Colour output -- Draw Pixel
    Ci = {pixel_value, pixel_value, pixel_value, alpha};
    DrawRectangle(30+x,40+y, pixel_size, pixel_size, Ci);

    // If end of pattern in X then increment Y and clear X
    if(inc_x == 7){ inc_x = 0; x = 0; ++inc_y; y += pixel_size+1;}
    else{ ++inc_x; x += pixel_size+2; }
    // Y is one step behind X hence 8 before needing clear Y
    if(inc_y == 8){ inc_y = 0; y = 0;}
  }

}