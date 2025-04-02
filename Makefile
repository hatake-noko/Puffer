CC = gcc
INCLUDE = -I include
DELIMITER = /
FILE = main
BUILDDIR = build
BUILD = $(addprefix $(BUILDDIR)(DELIMITER), $(addsuffix .o, $(FILE)))
TARGET = bin/clean.exe

.SUFFIXES: .c .o

$(TARGET): $(BUILD)
	mkdir -p $(dir $@)
	$(CC) $^ -lm -o $(TARGET)

$(BUILDDIR)$(DELIMITER)%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(INCLUDE) -c $< -DDEV -o $@

all: $(TARGET)

clean:
	rm -rf $(BUILD)
