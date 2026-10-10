#include <stdio.h>
#include <string.h>
#include "chip8.h"

int main(void){
    Chip8 chip;
    chip8_init(&chip);

    if (!chip8_load_rom(&chip, "test.rom")) {
        printf("Failed to load ROM\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        chip8_cycle(&chip);
    }

    return 0;
}