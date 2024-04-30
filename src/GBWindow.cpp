#include "GBWindow.hpp"
#include "raylib.h"
#include "ppu.hpp"
#include "utility.hpp"
#include <iostream>
#include <cstdint>
#include <vector>

#define SCREEN_SIZE_X 800
#define SCREEN_SIZE_Y 800
using std::vector;

// More C based syntax, raylib created window
void GB::Window::Create(){

  SetTraceLogLevel(LOG_ERROR);
  // Initialization
  const int screenWidth = SCREEN_SIZE_X;
  const int screenHeight = SCREEN_SIZE_Y;
  InitWindow(screenWidth, screenHeight, "Tile");
  SetTargetFPS(60);

  while(!WindowShouldClose()){
    BeginDrawing();

    ClearBackground(GRAY);
    DrawText("Hello World!", 150, 180, 20, LIGHTGRAY);
    PPU::DrawTilemap();

    EndDrawing();
  }
  CloseWindow(); 
}