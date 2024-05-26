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

  int x_min = 16; int x_max = 176;
  int y_min = 16; int y_max = 160;

  PPU::FormatTilemap();

  while(!WindowShouldClose()){
    BeginDrawing();

    ClearBackground(GRAY);
    DrawText("Hello World!", 150, 180, 20, LIGHTGRAY);

    PPU::DrawTileMap();

    EndDrawing();
  }
  CloseWindow(); 
}

// Temporary
void window_test(const char* arg_1, const char* arg_2){
  Cartridge Cartridge_b(arg_2);
  Cartridge_b.transfer_tilemap();
  Cartridge Cartridge_a(arg_1);
  Cartridge_a.transfer_tileset();
  GB::Window::Create();
}
