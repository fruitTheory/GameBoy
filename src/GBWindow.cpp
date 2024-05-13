#include "GBWindow.hpp"
#include "raylib.h"
#include "ppu.hpp"
#include "utility.hpp"
#include "cartridge.hpp"
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

// Temporary
void window_test(char* argv[]){
  Cartridge Cartridge_b(argv[3]);
  Cartridge_b.transfer_tilemap();
  Cartridge Cartridge_a(argv[2]);
  Cartridge_a.transfer_tileset();
  GB::Window::Create();
}
