/*
** EPITECH PROJECT, 2021
** my_printf.h
** File description:
** Header that contains the prototypes of all the
** functions for the my_printf
*/

#ifndef MY_PRINTF_H_
    #define MY_PRINTF_H_

    #define TYPE_NOTHING 0
    #define TYPE_INT 1
    #define TYPE_UINT 2
    #define TYPE_LONG 3
    #define TYPE_ULONG 4
    #define TYPE_LONG_LONG 5
    #define TYPE_ULONG_LONG 6
    #define TYPE_STR 7
    #define TYPE_VOID 9

typedef struct s_flag {
    char spec;
    int type;
    int width;
    int max_width;
    char *flags;
    int pos;
} flag_t;

int my_printf(char const *format, ...);
char *unsigned_int(unsigned int);
char *unsigned_hex(unsigned long long);
char *unsigned_hex_uppercase(unsigned long long);
char *pointer_addr(void *);
char *signed_octal(int);
char *show_str_octal(char *);
char *unsigned_bin(unsigned long long);
char *my_putunbr_base(unsigned long long nbr, char const *base);
char *octal(unsigned long long nbr);
char *print_percent(void);
char *my_put_long(long);
char *my_put_long_long(long long);
char *unsigned_long(unsigned long nb);
char *unsigned_long_long(unsigned long long nb);
char *putstr_pf(char *str);
char *putchar_pf(char c);
char *putnbr_pf(int nbr);
int is_in(char ch, char *str);
char *my_strcat_m(char *str1, char *str2);
char *my_strcpy_m(char *str);
char *my_str_addchar(char *str1, char c);
void put_result(flag_t *flag, char *result, int *chars_written);
char *left_fill(flag_t *flag, char *result, char fill);
char *left_justify(flag_t *flag, char *result, char fill);
flag_t *parse_flag(char const *format, int *c);

#endif
