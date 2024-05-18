#pragma once

class GameBoy{
  
  public:
  static void Init(const char* cartridge);
  static void Run();
  static void Display(const char* tileset, const char* tilemap);
};