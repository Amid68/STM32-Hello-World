# Toolchain
CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
SIZE = arm-none-eabi-size

# Directories
SRCDIR = src
INCDIR = inc
STARTUPDIR = startup
LDDIR = ld

# Files
C_SOURCES = $(wildcard $(SRCDIR)/*.c)
ASM_SOURCES = $(wildcard $(STARTUPDIR)/startup_stm32f446xx.s)

# Object files
OBJ = $(C_SOURCES:.c=.o) $(ASM_SOURCES:.s=.o)

# Flags
CFLAGS = -mcpu=cortex-m4 -mthumb -O0 -g \
         -I$(INCDIR) \
         -T$(LDDIR)/stm32f446xx.ld \
         -Wall \
         -ffunction-sections -fdata-sections \
         -nostartfiles

LDFLAGS = -mcpu=cortex-m4 -mthumb -O0 -g \
          -T$(LDDIR)/stm32f446xx.ld \
          -Wl,--gc-sections \
          -Wl,-Map=output.map

# Target
TARGET = main

# Build rules
all: $(TARGET).elf $(TARGET).bin

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.s
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET).elf: $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@
	$(SIZE) $@

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@

clean:
	rm -f $(SRCDIR)/*.o $(STARTUPDIR)/*.o $(TARGET).elf $(TARGET).bin output.map
