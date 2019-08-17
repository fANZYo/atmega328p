# Target filename based on parent directory name
TARGET = $(lastword $(subst /, ,$(CURDIR)))

# MCU specificities
MCU = atmega328p
F_CPU = 1000000UL

# Programmer type
ISP = avrisp2

# Toolchain
CC = avr-gcc
OBJCOPY = avr-objcopy
AVRDUDE = avrdude

# Compilation options
CCFLAGS = -DF_CPU=${F_CPU}

# Magic!
%.o: %.c
	${CC} ${CCFLAGS} -g -Os -mmcu=${MCU} -c $<

%.elf: %.o
	${CC} -g -mmcu=${MCU} -o $@ $<

%.hex: %.elf
	${OBJCOPY} -j .text -j .data -O ihex $< $@

flash: ${TARGET}.hex
	${AVRDUDE} -c ${ISP} -p ${MCU} -U flash:w:$<

clean:
	rm -f ${TARGET}.hex ${TARGET}.elf ${TARGET}.o
