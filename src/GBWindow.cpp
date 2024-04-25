#include "GBWindow.hpp"
#include "raylib.h"
#include "ppu.hpp"
#include <iostream>
#include <cstdint>

void create_window(){

  // Initialization
  const int screenWidth = 400;
  const int screenHeight = 400;
  InitWindow(screenWidth, screenHeight, "Title");
  SetTargetFPS(60);
  int input_value = 2;
  uint8_t pixel = 100;
  Color c;

  while(!WindowShouldClose()){
    BeginDrawing();
    ClearBackground(BLACK);
    DrawText("Hello World!", 150, 180, 20, LIGHTGRAY);
    DrawFPS(10, 10);
    for(int y = 0; y < 50; y+=6){
      for(int x = 0; x < 50; x+=7){
        switch(input_value){
          case 0:
            pixel = shade[0];
            break;
          case 1:
            pixel = shade[1];
            break;
          case 2:
            pixel = shade[2];
            break;
          case 3:
            pixel = shade[3];
            break;
        }
        c = {pixel, pixel, pixel, 255};
        DrawRectangle(30+x,30+y,5,5, c);
      }
    }
    EndDrawing();
  }
  CloseWindow(); 
}