#pragma once

#define RAM_SIZE 8192
#define VRAM_SIZE 8192
#define ROM_BANK_0_SIZE 16383
#define ROM_BANK_1_SIZE 16383
#define ADDRESS_BUS 65535
#define BYTE 0xFF

#define PIXELS 256
#define TILES 32
#define TILE_PIXELS 8

#define endline std::cout << std::endl 
#define print(value) std::cout << (value) << std::endl
#define printhex(value) std::cout << std::format("{:02X}", value) << std::endl;

#define LY 0xFF44 // LCD Y coordinate
#define NR52 0xFF26 // Sound on/off

/*

0000	3FFF	16 KiB ROM bank 00	From cartridge, usually a fixed bank
4000	7FFF	16 KiB ROM Bank 01–NN	From cartridge, switchable bank via mapper (if any)
8000	9FFF	8 KiB Video RAM (VRAM)	In CGB mode, switchable bank 0/1
A000	BFFF	8 KiB External RAM	From cartridge, switchable bank if any
C000	CFFF	4 KiB Work RAM (WRAM)	
D000	DFFF	4 KiB Work RAM (WRAM)	In CGB mode, switchable bank 1–7
E000	FDFF	Echo RAM (mirror of C000–DDFF)	Nintendo says use of this area is prohibited.
FE00	FE9F	Object attribute memory (OAM)	
FEA0	FEFF	Not Usable	Nintendo says use of this area is prohibited.
FF00	FF7F	I/O Registers	
FF80	FFFE	High RAM (HRAM)	
FFFF	FFFF	Interrupt Enable register (IE)	


$FF00	-	Joypad input
$FF01	$FF02	-	Serial transfer
$FF04	$FF07	-	Timer and divider
$FF10	$FF26	-	Audio
$FF30	$FF3F	-	Wave pattern
$FF40	$FF4B	-	LCD Control, Status, Position, Scrolling, and Palettes
$FF4F	-	VRAM Bank Select
$FF50	-	Set to non-zero to disable boot ROM
$FF51	$FF55	-	VRAM DMA
$FF68	$FF6B	-	BG / OBJ Palettes
$FF70	-	WRAM Bank Select

*/