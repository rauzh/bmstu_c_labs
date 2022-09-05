#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

typedef enum
{
    FALSE,
    TRUE = 1
} bool;

char *my_strpbrk(const char *str, const char *str_char_set)
{
    const char *scs;
    size_t str_symb, str_char_set_symb;

    while ((str_symb = *str++) != 0)
    {
        for (scs = str_char_set; (str_char_set_symb = *scs++) != '\0';)
            if (str_char_set_symb == str_symb)                
                return (char *)(str - 1);
    }

    return NULL;    
}

size_t my_strspn(const char *str, const char *str_char_set)
{
    const char *scs;
    size_t str_symb, str_char_set_symb;
    size_t count = 0;
    bool flag = FALSE;

    while ((str_symb = *str++) != 0)
    {
        flag = FALSE;
        for (scs = str_char_set; (str_char_set_symb = *scs++) != '\0';)
            if (str_char_set_symb == str_symb)
                flag = TRUE;
        
        if (flag)
            count++;
        else
            break;
    }

    return count;
}

size_t my_strcspn(const char *str, const char *str_char_set)
{
    const char *scs;
    size_t str_symb, str_char_set_symb;
    size_t count = 0;
    bool flag = FALSE;

    while ((str_symb = *str++) != 0)
    {
        flag = TRUE;
        for (scs = str_char_set; (str_char_set_symb = *scs++) != '\0';)
            if (str_char_set_symb == str_symb)
                flag = FALSE;
        
        if (flag)
            count++;
        else
            break;
    }

    return count;
}

char *my_strchr(const char *str, int num)
{
    do
    {        
        if (*str == num)
            return (char *)(str);
    }
    while (*str++);

    return NULL;
}

char *my_strrchr(const char *str, int num)
{
    char *rs = 0;

    do
    {
        if (*str == num)
            rs = (char *)(str);
    }
    while (*str++);

    return rs;
}

int main(void)
{
    char *my_result_str = NULL;
    char *result_str = NULL;
    size_t my_result, result;
    char string[100] = "Five years ago XO TOUR Llife dropped out.";
    int rc = 0, count = 0;
 
    my_result_str = my_strpbrk(string, "qXw");
    result_str = strpbrk(string, "qXw");

    rc = strcmp(my_result_str, result_str);

    if (rc != EXIT_SUCCESS)
        count++;

    my_result = my_strspn(string, "ieFv");
    result = strspn(string, "ieFv");

    if (my_result != result)
        count++;

    my_result = my_strcspn(string, "e");
    result = strcspn(string, "e");

    if (my_result != result)
        count++;

    my_result_str = my_strchr(string, ' ');
    result_str = strchr(string, ' ');

    rc = strcmp(my_result_str, result_str);

    if (rc != EXIT_SUCCESS)
        count++;
    
    my_result_str = my_strrchr(string, 'r');
    result_str = strrchr(string, 'r');

    rc = strcmp(my_result_str, result_str);

    if (rc != EXIT_SUCCESS)
        count++;

    printf("%d\n", count);

    return EXIT_SUCCESS;
}
