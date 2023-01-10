# Компилятор
CC := gcc

INC_DIR := ./inc

LIB_SRC_DIR := ./lib/src
LIB_OUT_DIR := ./lib/out
LIB_INC_DIR := ./lib/inc

# Опции компиляции
CFLAGS_PROG := -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal $(shell pkg-config --cflags check)
CFLAGS_LIB := -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal -I$(LIB_INC_DIR)

# Все c-файлы
SRCS := $(wildcard src/*.c)
UNIT_SRCS := $(wildcard unit_tests/*.c)
LIB_SRCS := $(wildcard $(LIB_SRC_DIR)/*.c)

# Общие объектные файлы
OBJS_MAIN := out/main.o out/final_funcs.o
OBJS_LIB := $(LIB_SRCS:$(LIB_SRC_DIR)/%.c=$(LIB_OUT_DIR)/%.o)

app.exe: $(OBJS_MAIN) lib/out/libtask.a
	$(CC) -I$(INC_DIR) -o $@ $(OBJS_MAIN) -L $(LIB_OUT_DIR) -ltask

dapp.exe: $(OBJS_MAIN) lib/out/libtask.so
	$(CC) -I$(INC_DIR) -o $@ $(OBJS_MAIN) -L $(LIB_OUT_DIR) -ltask

unit_tests.exe: out/check_main.o out/check_mysort.o out/check_key.o
	$(CC) -I$(INC_DIR) -o $@ $^ `pkg-config --cflags --libs check` -L $(LIB_OUT_DIR) -ltask

dunit_tests.exe: out/check_main.o out/check_key.o out/check_mysort.o lib/out/libtask.so
	$(CC) -I$(INC_DIR) -o $@ out/check_main.o out/check_key.o out/check_mysort.o `pkg-config --cflags --libs check` -L $(LIB_OUT_DIR) -ltask

out/%.d: src/%.c
	mkdir -p out
	$(CC) -I$(INC_DIR) -I$(LIB_INC_DIR) -M $< > $@

out/%.d: unit_tests/%.c
	mkdir -p out
	$(CC) -I$(INC_DIR) -I$(LIB_INC_DIR) -M $< > $@

out/%.o : src/%.c
	$(CC) $(CFLAGS_PROG) -I$(INC_DIR) -I$(LIB_INC_DIR) -c $< -o $@

out/%.o : unit_tests/%.c
	$(CC) $(CFLAGS_PROG) -I$(INC_DIR) -I$(LIB_INC_DIR) -c $< -o $@

lib/out/%.d: lib/src/%.c
	mkdir -p lib/out
	$(CC) -I$(LIB_INC_DIR) -M $< > $@

lib/out/%.o : lib/src/%.c
	$(CC) $(CFLAGS_LIB) -c $< -o $@

lib/out/libtask.a : $(OBJS_LIB)
	ar cr $@ $^
	ranlib $@

lib/out/libtask.so: $(CFLAGS_LIB) += -fPIC
lib/out/libtask.so: $(OBJS_LIB)
	$(CC) -o $@ -shared $^
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:lib/out

include $(SRCS:src/%.c=out/%.d)
include $(UNIT_SRCS:unit_tests/%.c=out/%.d)
include $(LIB_SRCS:$(LIB_SRC_DIR)/%.c=$(LIB_OUT_DIR)/%.d)

.PHONY : build_debug build_release clear func

build_debug: CFLAGS_PROG += -g
build_debug: app.exe

build_release: CFLAGS_PROG += -o
build_release: app.exe

#  unit: CFLAGS += -lcheck -lpthread -lrt
unit: unit_tests.exe

clear :
	rm -f out/*.txt out/*.o out/*.d *.exe *.out lib/out/*.txt lib/out/*.o lib/out/*.so lib/out/*.d










