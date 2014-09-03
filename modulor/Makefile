CC := avr-gcc
LD := avr-gcc
MCU := attiny2313

SRCS ?= $(wildcard *.c **/*.c)
OBJS ?= $(SRCS:.c=.o)

TARGETS ?= $(patsubst targets/%.c,%.elf,$(wildcard targets/*.c))

CFLAGS := -std=c11 -Wall -Wextra -Werror -pedantic -mmcu=$(MCU) -g -Os -flto $(CFLAGS)

.PHONY: all flash clean distclean

all: $(TARGETS)
	@avr-size -C --mcu=$(MCU) $^

%.o: %.c Makefile
	$(CC) $(CFLAGS) -c -o $@ $<

%.elf: targets/%.o $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

distclean: clean

clean:
	$(RM) $(OBJS)
	$(RM) $(TARGETS)
