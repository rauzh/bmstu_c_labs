#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "snprintf.h"

#define SWAP(type, a, b) {type c = a; a = b; b = c;}

static void reverse_string(char *string, const int length)
{
    for (int i = 0; i < length / 2; i++)
        SWAP(char, *(string - i - 1), *(string - length + i));
}

static int find_number_length(char *string, long number, const int base)
{
    int length = 0;
    bool is_neg = number < 0 ? true : false;
    number = labs(number);

    do
    {
        ++length;
        *(string++) = number % base + ((number % base < 10) ? '0' : 'a' - 10);
    } while (number /= base);

    if (is_neg)
    {
        *string++ = '-';
        length++;
    }

    reverse_string(string, length);

    return length;
}

static void add_number_to_string(char *restrict *buff, int *size, const int size_limit, const int base, long number)
{
    char number_buff[MAX_INT_LEN];
    int number_length = find_number_length(number_buff, number, base);
    int buff_index = 0;

    for (; buff_index < number_length && *size < size_limit; buff_index++, (*size)++)
        *((*buff)++) = *(number_buff + buff_index);

    *size += (number_length - buff_index);
}

static void add_char_to_string(char *restrict *buff, int *size, const int size_limit, int symb)
{
    if (*size < size_limit)
    {
        **buff = symb;
        ++*buff;
    }

    (*size)++;
}

static void add_str_to_str(char *restrict *buff, int *size, const int size_limit, char *str)
{
    if (str == NULL)
        str = "(null)";

    while (*str != '\0')
        add_char_to_string(buff, size, size_limit, *str++);
}

static void proc_arg(char *restrict *buff, int *size, const char *restrict *format, const int size_limit, va_list args)
{
    bool is_short = (*(++(*format)) == 'h') ? true : false;
    int base = 10;
    void *str;

    is_short ? (*format)++ : *format;

    switch (**format)
    {
        case 'i':
        case 'd':
            if (is_short)
                add_number_to_string(buff, size, size_limit, base, va_arg(args, int));
            else
                add_number_to_string(buff, size, size_limit, base, va_arg(args, int));
            break;
        case 'x':
            base = 16;
            add_number_to_string(buff, size, size_limit, base, va_arg(args, unsigned));
            break;
        case 'c':
            add_char_to_string(buff, size, size_limit, va_arg(args, int));
            break;
        case 's':
            str = va_arg(args, void *);
            add_str_to_str(buff, size, size_limit, str);
            break;
        default:
            if (++(*size) < size_limit)
            {
                *(*buff)++ = '%';
                *format = **format != '%' ? (*format) - 1 : *format;
            }
    }
}

int my_snprintf(char *restrict buff, const int size, const char *restrict format, ...)
{
    va_list args;
    int buff_size = 0;

    va_start(args, format);

    for (; *format; format++)
    {
        if (*format == '%')
            proc_arg(&buff, &buff_size, &format, size, args);
        else if (buff_size++ < size)
            *(buff++) = *format;
    }
    if (*format == '%')
        proc_arg(&buff, &buff_size, &format, size, args);
    else if (buff_size++ < size)
        *(buff++) = *format;

    if (size)
        *(buff - 1) = '\0';

    va_end(args);

    return --buff_size;
}

