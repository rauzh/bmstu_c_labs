#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
#define ARRAY_SIZE 128 // если каждое слово состоит из одной буквы
#define STR_SIZE 256 
#define NUM_OF_SEPARATORS 9
#define EQUAL 0
#define WORD_SIZE 16 // +1
 
#define EXIT_EMPTY_LINE 33
#define EXIT_LINE_LENGTH_LIMIT 34
#define EXIT_WORD_LENGTH_LIMIT 35
#define EXIT_NO_WORDS 36
 
#define SWAP(x, y) do { int SWAP = x; x = y; y = SWAP; } while (0)
 
#define EMPTY_LINE do \
        { fprintf(stderr, "Empty line input is forbidden!\n"); \
        return EXIT_EMPTY_LINE; } while(0)

#define BIG_LINE do \
        { fprintf(stderr, "The line is way too big!\n"); \
        return EXIT_LINE_LENGTH_LIMIT; } while(0)

#define BIG_WORD do \
        { fprintf(stderr, "The word was way too big!\n"); \
        return EXIT_WORD_LENGTH_LIMIT; } while(0)

#define NO_WORDS do \
        { fprintf(stderr, "No words!\n"); \
        return EXIT_NO_WORDS; } while(0) 
 
#define SEPARATORS " -.,:;?!"
 
typedef enum
{
    FALSE,
    TRUE = 1
} bool;
 
 
size_t input_one_line(char *str, size_t n)
{
    int ch;
    size_t i = 0;
 
    while ((ch = getchar()) != '\n' && ch != EOF)
        if (i < n)
            str[i++] = ch;
        else
            return STR_SIZE + 1;
 
    str[i] = '\0';
 
    return i;
}

void move_to_first_word(char *str, size_t n, size_t *n_first_word)
{
    while ((str[*n_first_word] == '\0') && (*n_first_word < n + 1))
        ((*n_first_word)++);
}
 
void nulify_separators(char *str, size_t n, size_t *count, char *separators)
{
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < NUM_OF_SEPARATORS - 1; j++)
            if (str[i] == separators[j])
            {
                str[i] = '\0';
                ((*count)++);
            }
}

int split_str_by_null(char *str, size_t n, size_t n_first_word, size_t *word_len, char arr[][WORD_SIZE + 1], size_t *len_arr)
{
    for (size_t k = n_first_word; k < n + 1; k++)
        if (str[k] != '\0')
        {
            arr[*len_arr][*word_len] = str[k];
            ((*word_len)++);

            if (*word_len >= WORD_SIZE)
                return EXIT_WORD_LENGTH_LIMIT;
        }
        else if (str[k - 1] != '\0')
        {
            arr[*len_arr][*word_len] = '\0';
            ((*len_arr)++);
            *word_len = 0;
        }

    return EXIT_SUCCESS;
}

int get_words(char *str, size_t n, char arr[][WORD_SIZE + 1], size_t *len_arr)
{
    char separators[NUM_OF_SEPARATORS] = SEPARATORS;
    size_t count = 0;

    nulify_separators(str, n, &count, separators);

    if (count == n)
        return EXIT_NO_WORDS;

    size_t word_len = 0, n_first_word = 0;

    move_to_first_word(str, n, &n_first_word);

    int rc = split_str_by_null(str, n, n_first_word, &word_len, arr, len_arr);

    if (rc != EXIT_SUCCESS)
        return EXIT_WORD_LENGTH_LIMIT;

    return EXIT_SUCCESS;
}
 
size_t del_word(char arr[][WORD_SIZE + 1], size_t n, size_t num_elem_to_del)
{
    for (size_t i = num_elem_to_del; i < n - 1; ++i)
        strcpy(arr[i], arr[i + 1]);

    return (--n);
}
 
size_t make_unique(char arr[][WORD_SIZE + 1], size_t n)
{
    for (size_t i = 0; i < n - 1; ++i)
        for (size_t j = i + 1; j < n; ++j)
            if (strcmp(arr[i], arr[j]) == EQUAL)
            {    
                n = del_word(arr, n, j);
                (--j);
            }
    
    return n;
}
 
void print_array_of_words(char arr[][WORD_SIZE + 1], size_t n)
{
    for (size_t i = 0; i < n; ++i)
        fprintf(stdout, "%s ", arr[i]);
}
 
void lexicography_sort(char arr[][WORD_SIZE + 1], size_t n)
{
    size_t min_idx;
 
    for (size_t i = 0; i < n; ++i)
    {
        min_idx = i;
 
        for (size_t j = i + 1; j < n; ++j)
            if (strcmp(arr[j], arr[min_idx]) < EQUAL)
                min_idx = j;
 
        for (size_t k = 0; k < WORD_SIZE; ++k)
            SWAP(arr[i][k], arr[min_idx][k]);
    }
}
 
int main(void)
{
    char arr[ARRAY_SIZE][WORD_SIZE + 1];
    char str[STR_SIZE + 1];
 
    fprintf(stdout, "Input line: ");
 
    size_t len_str = input_one_line(str, STR_SIZE);
 
    if (len_str == 0)
        EMPTY_LINE;
 
    if (len_str > STR_SIZE)
        BIG_LINE;
 
    size_t len_arr = 0;
    int rc = get_words(str, len_str, arr, &len_arr);

    if (rc == EXIT_WORD_LENGTH_LIMIT)
        BIG_WORD;

    if (rc == EXIT_NO_WORDS)
        NO_WORDS;

    len_arr = make_unique(arr, len_arr);
 
    if (len_arr == 1)
        NO_WORDS;

    lexicography_sort(arr, len_arr);
 
    fprintf(stdout, "Result: ");
    print_array_of_words(arr, len_arr);
    fprintf(stdout, "\n");
 
    return EXIT_SUCCESS;
}
