.PHONY: clean run

chip8: main.c chip8.c chip8.h
	gcc main.c chip8.c -o chip8

clean:
	rm -f chip8

run: chip8
	./chip8