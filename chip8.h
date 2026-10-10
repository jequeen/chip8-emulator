#ifndef CHIP8_H
#define CHIP8_H

#include <stdint.h>

#define MEMORY_SIZE 4096
#define NUM_REGISTERS 16
#define STACK_SIZE 16
#define DISPLAY_WIDTH 64
#define DISPLAY_HEIGHT 32
#define NUM_KEYS 16
#define PROGRAM_START 0x200

typedef struct {
    uint8_t memory[MEMORY_SIZE];
    uint8_t V[NUM_REGISTERS];
    uint16_t I;
    uint16_t pc;
    uint16_t stack[STACK_SIZE];
    uint8_t sp;
    uint8_t delay_timer;
    uint8_t sound_timer;
    uint8_t display[DISPLAY_WIDTH * DISPLAY_HEIGHT];
    uint8_t keypad[NUM_KEYS];
} Chip8;

void chip8_init(Chip8 *chip);

int chip8_load_rom(Chip8 *chip, const char *rom);

int chip8_cycle(Chip8 *chip);

#endif