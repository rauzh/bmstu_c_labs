#ifndef __LAB_10_DEFS_H
#define __LAB_10_DEFS_H

#define INVALID_ARGS_AMOUNT 240
#define NO_FILE             241
// #define OVERFLOW            242
#define INVALID_INPUT       243
#define EMPTY_FILE          244
#define NO_SPECIFIC_ITEM    245
#define CLOSE_FILE_ERROR    246
#define MEMORY_ERROR        247

#define EQUAL                0
#define CORRECT_COUNT        1

#define COMMAND_LEN          4
#define CORRECT_ITEM         3
#define CORRECT_FIELD        1
#define END_OF_FILE_ERR     -1
#define GETLINE_ERR         -1
#define RESIZE_STEP          2

typedef enum
{
	GET_VAL = 1,
	GET_DDX = 2,
	GET_SUM = 3,
	GET_DVD = 4
} command_t;


#endif //LAB_10_DEFS_H
