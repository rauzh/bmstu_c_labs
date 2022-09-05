#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STR_SIZE 257
#define WORD_SIZE 16
#define ARRAY_SIZE 128

#define EXIT_EMPTY_LINE 33
#define EXIT_LINE_LENGTH_LIMIT 34
#define EXIT_WORD_LENGTH_LIMIT 35
#define EXIT_NO_UNIQUE_WORDS 37
#define EXIT_NO_WORDS 38

#define SEPARATORS " -.,:;?!"

#define EMPTY_LINE do \
        { fprintf(stderr, "Empty line input is forbidden!\n"); \
        return EXIT_EMPTY_LINE; } while(0)

#define BIG_LINE do \
        { fprintf(stderr, "The line is way too big!\n"); \
        return EXIT_LINE_LENGTH_LIMIT; } while(0)

#define BIG_WORD do \
        { fprintf(stderr, "The word was way too big!\n"); \
        return EXIT_WORD_LENGTH_LIMIT; } while(0)

#define NO_UNIQUE do \
        { fprintf(stderr, "No unique words!\n"); \
        return EXIT_NO_UNIQUE_WORDS; } while(0)

#define NO_WORDS do \
        { fprintf(stderr, "No words!\n"); \
        return EXIT_NO_WORDS; } while(0)

typedef enum
{
    FALSE,
    TRUE = 1
} bool;

int input_one_line(char *str, size_t *len_str)
{
    fprintf(stdout, "Input line: ");

    if (!fgets(str, STR_SIZE, stdin))
    {
        *len_str = 0;
        return EXIT_FAILURE;
    }

    *len_str = strlen(str);

    if ((*len_str) > STR_SIZE)
        return EXIT_LINE_LENGTH_LIMIT;

    if (!(*len_str))
    {
        *len_str = 0;
        return EXIT_FAILURE;
    }

    if (str[0] == '\n')
    {
        *len_str = 0;
        return EXIT_FAILURE;
    }

    if (str[*len_str - 1] == '\n')
        str[--(*len_str)] = '\0';

    return EXIT_SUCCESS;
}
 
int get_words(char *str, size_t len_str, char arr[][WORD_SIZE + 1], size_t *len_arr)
{
    char word[WORD_SIZE + 1];
    size_t len_word = 0;
    size_t temp = *len_arr;

    for (size_t i = 0; i <= len_str; ++i)
    {
        const char str_ch[] = { str[i], '\0' };

        if (!strcspn(str_ch, SEPARATORS) || (i == len_str))
        {
            if (len_word >= 1)
            {
                word[len_word] = '\0';
                strcpy(arr[*len_arr], word);
                (*len_arr)++;
                strcpy(word, "");
                len_word = 0;
            }
        }
        else if (len_word < WORD_SIZE)
            word[len_word++] = str[i];
        else
            return EXIT_WORD_LENGTH_LIMIT;
    }

    if (*len_arr == temp)
        return EXIT_NO_WORDS;

    return EXIT_SUCCESS;
}

void del_repeat_letters(char *word)
{
    size_t len_w = strlen(word);
    char new_word[WORD_SIZE] = " ";
    size_t count = 0;

    for (size_t i = 0; i < len_w; ++i)
    {
        for (size_t j = 0; j < i; ++j)
            if (word[i] == word[j])
                (++count);

        if (count == 0)
        {
            const char str_ch[] = { word[i], '\0' };
            strcat(new_word, str_ch);
        }

        count = 0;
    }

    strcpy(word, new_word);
}

int get_new_line(char arr[][WORD_SIZE + 1], size_t len_arr, char *line)
{
    char last_word[WORD_SIZE], tmp_word[WORD_SIZE];
    int rc = EXIT_NO_UNIQUE_WORDS;

    strcpy(last_word, arr[len_arr - 1]);

    for (int i = len_arr - 2; i >= 0; i--)
        if (strcmp(last_word, arr[i]))
        {
            strcpy(tmp_word, arr[i]);
            del_repeat_letters(tmp_word);
            strcat(line, tmp_word);
            rc = EXIT_SUCCESS;
        }

    return rc;
}

int main(void)
{
    char arr[ARRAY_SIZE][WORD_SIZE + 1];
    char str[STR_SIZE];

    size_t len_str = 0;
    
    int rc = input_one_line(str, &len_str);

    if (len_str == 0)
        EMPTY_LINE;

    if (rc == EXIT_LINE_LENGTH_LIMIT)
        BIG_LINE;

    size_t len_arr = 0;
    rc = get_words(str, len_str, arr, &len_arr);

    if (rc == EXIT_WORD_LENGTH_LIMIT)
        BIG_WORD;

    if (rc == EXIT_NO_WORDS)
        NO_WORDS;

    char new_str[STR_SIZE] = "";
    rc = get_new_line(arr, len_arr, new_str);

    if (rc != EXIT_SUCCESS)
        NO_UNIQUE;

    fprintf(stdout, "Result:%s\n", new_str);

    return EXIT_SUCCESS;
}
