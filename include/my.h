/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>
#include <stdbool.h>

/** Lib functions **/

char *gnl(int fd);
char **m_arraydup(char const **src);
int m_arraylen(char const **src);
char *m_cleans(char *str, bool tfree);
void m_putarray(char **array, char c, int fd);
int m_puts(char const *str, int s);
char *m_retbase(long long nb, int base);
char *m_revs(char *str);
char **m_sarray(char *str, char c, bool t_free);
char *m_scat(char *dest, char *src, int pos, int n);
char *m_sdup(char const *src, char ch);
int m_slen(char const *str);
int m_scmp(char const *str1, char const *str2, char lim);
char *m_int(va_list ap, char *str, char *buf);
char *m_char(va_list ap, char *str, char *buf);
char *m_string(va_list ap, char *str, char *buf);
char *m_array(va_list ap, char *str, char *buf);
char *m_arrays(char **array, char c);
char *m_printf(int fd, char *str, ...);
long m_getnb(char const *str);
char m_sisnb(char *str, int neg);
char m_cisnb(char c, int neg);
char m_template(char *temp, char *str);
char **m_arraycat(char **dest, char *src, int pos, char t_free);
int m_spelen(char const *str, char c);
int m_intarraylen(int *array);
char *m_iarray(va_list ap, char *str, char *buf);
char *m_maj_iarray(va_list ap, char *str, char *buf);
char *m_realloc(char *str, int size);
char *cut_int(char *str, int begin, int end);
char *cut_char(char *str, char begin, char end);
void m_scpy(char const *src, char *dest, char ch);
void free_array(char **array);
int m_intlen(int *array);
int *m_intcat(int *array, int new_i);
void my_puts_fd(char const *, int);
char *m_maj_hex(va_list, char *, char *);
char *m_hex(va_list, char *, char *);


/** Macros **/

#define SUCCESS 0
#define FAILURE 84
#define POSITIVE 1
#define READ_SIZE 100
#define RANDOM 12
#define UNUSED __attribute__ ((unused))
#define FIRST 1
#define SECOND 2
#define BOTH 3

#endif /* MY_H_ */
