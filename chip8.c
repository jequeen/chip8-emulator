#include <stdio.h>
#include <string.h>
#include "chip8.h"

void chip8_init(Chip8 *chip) {
    memset(chip, 0, sizeof(Chip8));
    chip->pc = PROGRAM_START;
}

int chip8_load_rom(Chip8 *chip, const char *rom) {
    int max_elements = MEMORY_SIZE - PROGRAM_START;
    FILE *file = fopen(rom, "rb");

    if (!file) {
        return 0;
    }

    fread(&chip->memory[PROGRAM_START], 1, max_elements, file);
    fclose(file);
    return 1;
}

void chip8_cycle(Chip8 *chip) {
    uint16_t opcode = (chip->memory[chip->pc] << 8) | chip->memory[chip->pc + 1];
    chip->pc += 2;

    printf("Opcode: %04X\n", opcode);
}
