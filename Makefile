CC = z:\tcc\gcc
INCLUDE = -I include
DELIMITER = \
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

# z:\tcc\gcc -c src\main.c -I include -o build\main.o
# z:\tcc\gcc -c src\info.c -I include -o build\info.o
# z:\tcc\gcc -c src\proc.c -I include -o build\proc.o
# z:\tcc\gcc -c src\puffer.c -I include -o build\puffer.o
# z:\tcc\gcc -c src\token.c -I include -o build\token.o
# z:\tcc\gcc build\main.o build\info.o build\proc.o build\puffer.o -o bin\clean.exe
