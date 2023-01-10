# Компилятор
CC := gcc

INC_DIR := ./inc

# Опции компиляции
CFLAGS := -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal $(shell pkg-config --cflags check)

# Общие объектные файлы
OBJS_MAIN := out/snprintf.o

# Все c-файлы
SRCS := $(wildcard src/*.c)
UNIT_SRCS := $(wildcard unit_tests/*.c)

app.exe: out/main.o $(OBJS_MAIN)
	$(CC) -I$(INC_DIR) -o $@ $^

unit_tests.exe: out/check_main.o out/check_snprintf.o $(OBJS_MAIN)
	$(CC) -I$(INC_DIR) -o $@ $^ `pkg-config --cflags --libs check`

out/%.d: src/%.c
	mkdir -p out
	$(CC) -I$(INC_DIR) -M $< > $@

out/%.d: unit_tests/%.c
	mkdir -p out
	$(CC) -I$(INC_DIR) -M $< > $@

out/%.o : src/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

out/%.o : unit_tests/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

include $(SRCS:src/%.c=out/%.d)
include $(UNIT_SRCS:unit_tests/%.c=out/%.d)

.PHONY : build_debug build_release clear func

build_debug: CFLAGS += -g3
build_debug: app.exe

build_release: CFLAGS += -o
build_release: app.exe

#  unit: CFLAGS += -lcheck -lpthread -lrt
unit: unit_tests.exe

func: app.exe
	echo "#!/bin/bash\n" > test_launcher.sh
	echo "cd func_tests/scripts\n" >> test_launcher.sh
	echo "./func_tests.sh\n" >> test_launcher.sh
	chmod 777 test_launcher.sh
	./test_launcher.sh
	rm test_launcher.sh
clear:
	rm -f out/*.txt out/*.o out/*.d *.exe *.out func_tests/scripts/*.txt
