# Компилятор
CC := gcc

INC_DIR := ./inc

# Опции компиляции
CFLAGS := -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal $(shell pkg-config --cflags check)

# Общие объектные файлы
OBJS_MAIN := out/main.o out/final_funcs.o out/read_print.o out/sort_funcs.o out/filter.o

# Все c-файлы
SRCS := $(wildcard src/*.c)
UNIT_SRCS := $(wildcard unit_tests/*.c)

app.exe: $(OBJS_MAIN)
	$(CC) -I$(INC_DIR) -o $@ $^

unit_tests.exe: out/check_main.o out/check_mysort.o out/check_key.o out/check_arr_mean.o out/sort_funcs.o out/filter.o
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

build_debug: CFLAGS += -g
build_debug: app.exe

build_release: CFLAGS += -o
build_release: app.exe

#  unit: CFLAGS += -lcheck -lpthread -lrt
unit: unit_tests.exe

clear :
	rm -f out/*.txt out/*.o out/*.d *.exe *.out
