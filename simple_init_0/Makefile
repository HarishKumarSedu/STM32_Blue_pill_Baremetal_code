CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
LD = arm-none-eabi-ld
BIN = arm-none-eabi-objcopy
STL = st-flash
CFLAGS  =  -c -mcpu=cortex-m3 -mthumb -std=gnu11 -Wall -g -O0   -c -o
LDFLAGS  = -nostdlib -Wl,-Map=firmware.map -o 

ifeq ($(OS),Windows_NT)
  RM = cmd /C del /Q /F
else
  RM = rm -f
endif

build: firmware.elf 

main.o: main.c 
	$(CC) $(CFLAGS) main.c main.o

startup.o: startup.c 
	$(CC) $(CFLAGS) startup.c startup.o

firmware.elf: linker.ld startup.o main.o  
	$(CC) -T linker.ld $(LDFLAGS) firmware.elf startup.o main.o 

firmware.bin: firmware.elf
	$(BIN) -O binary firmware.elf firmware.bin

flash: firmware.bin
	st-flash --reset write $< 0x8000000

clean:
	$(RM) firmware.* startup.o main.o 