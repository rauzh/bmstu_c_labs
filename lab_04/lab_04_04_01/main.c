#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STR_SIZE 257

#define EXIT_LINE_LENGTH_LIMIT 34

#define MOVE_TO_NON_SPACE(str, i) \
    do {i++;} while(isspace(str[i]))

#define END_CHECK \
    do {if (str[i] == '\0') \
        return EXIT_SUCCESS;} while(0)
                    
#define DIGITS_PASS \
    do {while (isdigit(str[i])) i++;} while(0)

#define PLUS_MINUS_PASS \
    do { \
    if (str[i] == '+') \
        i++; \
    else if (str[i] == '-') \
        i++;} while(0)

#define E_FORM_CHECK \
    do { \
    if ((str[i] == 'e') || (str[i] == 'E')) \
        { \
            i++; \
            \
            PLUS_MINUS_PASS; \
            \
            if (!(isdigit(str[i]))) \
                return EXIT_FAILURE; \
            else \
                DIGITS_PASS; \
        } \
    } while(0)

typedef enum
{
    FALSE,
    TRUE = 1
} bool;

int input_one_line(char *str, size_t *len_str)
{
    if (!fgets(str, STR_SIZE, stdin))
    {
        *len_str = 0;
        return EXIT_FAILURE;
    }

    *len_str = strlen(str);
    
    if ((*len_str) >= STR_SIZE - 1)
    {
        char overflow[STR_SIZE];
        if (fgets(overflow, STR_SIZE, stdin))
                return EXIT_LINE_LENGTH_LIMIT;
    }

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

bool only_spaces_end(char *str, size_t start)
{
    size_t i = start;
    while (!(isspace(str[i])) && (str[i] != '\0'))
        (i++);

    if (str[i] == '\0')
        return TRUE;

    size_t end = i;

    while (isspace(str[i]))
        (i++);

    if (str[i] == '\0')
    {
        str[end] = '\0';
        return TRUE;
    }
    else
        return FALSE;
}

int str_digit_check(char *str)
{
    size_t i = 0;

    if (isspace(str[0]))
        MOVE_TO_NON_SPACE(str, i);

    if (str[i] == '\0')
        return EXIT_FAILURE;

    if ((only_spaces_end(str, i)) == FALSE)
        return EXIT_FAILURE;

    PLUS_MINUS_PASS;

    if (isdigit(str[i]))
    {
        DIGITS_PASS;

        END_CHECK;

        if (str[i] == '.')
        {
            i++;
            
            if (isdigit(str[i]))
                DIGITS_PASS;
        }
        
        END_CHECK;

        E_FORM_CHECK; 

        END_CHECK;
    }
    else if ((str[i] == '.') && (isdigit(str[i + 1])))
    {
        i++;

        DIGITS_PASS;

        E_FORM_CHECK;

        END_CHECK;
    }

    return EXIT_FAILURE;
}

int main(void)
{ 
    char str[STR_SIZE];

    size_t len_str = 0;
    
    int rc = input_one_line(str, &len_str);

    if (len_str == 0)
    {
        printf("NO");
        return EXIT_SUCCESS;
    }
    if (rc == EXIT_LINE_LENGTH_LIMIT)
        return EXIT_FAILURE;

    rc = str_digit_check(str);

    if (rc == EXIT_SUCCESS)
        printf("YES\n");
    else
        printf("NO\n");

    return EXIT_SUCCESS;
}
