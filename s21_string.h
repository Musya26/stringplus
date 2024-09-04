#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_strerror.h"
typedef long unsigned s21_size_t;
#define S21_NULL (void *)0
typedef struct symbol {
  int flag_plus;
  int flag_minus;
  int flag_probel;
  int flag_null;
  int dlina_h;
  int dlina_l;
  int shirina;
  int tochnost;

} symbol;
int specificator_c(va_list args, char *str, int n, symbol *symbol);

int specificator_cl(va_list args, char *str, int n, symbol *symbol);

int specificator_s(va_list args, char *str, int n, symbol *symbol);

int specificator_u(va_list args, char *str, int n, symbol *symbol);

int specificator_ul(va_list args, char *str, int n, symbol *symbol);

int specificator_d(va_list args, char *str, int n, symbol *symbol);

int specificator_dl(va_list args, char *str, int n, struct symbol *symbol);

int specificator_f(va_list args, char *str, int n, symbol *symbol);

int parser_flags(char c, symbol *symbol);

int parser_shirina(char c, symbol *symbol);

int parser_tochnost(char c, symbol *symbol);

int parser_dlina(char c, symbol *symbol);

int begin_process(const char *format, int i, va_list args, char *str, int n,
                  symbol *symbol);

int flags_realization(char *str, int n, symbol *symbol, int flag_otric);

int shifts_print(char *str, int n, symbol *symbol, int probels);

int s21_sprintf(char *str, const char *format, ...);

void *s21_memchr(const void *str, int c, s21_size_t n);

int s21_memcmp(const void *str1, const void *str2, s21_size_t n);

void *s21_memcpy(void *dest, const void *src, s21_size_t n);

void *s21_memset(void *str, int c, size_t n);

char *s21_strncat(char *dest, const char *src, size_t n);

char *s21_strchr(const char *str, int c);

int s21_strncmp(const char *str1, const char *str2, s21_size_t n);

char *s21_strncpy(char *dest, const char *src, s21_size_t n);

char *s21_strcpy(char *dest, const char *src);

s21_size_t s21_strcspn(const char *str1, const char *str2);

char *s21_strerror(int errnum);

s21_size_t s21_strlen(const char *str);

char *s21_strpbrk(const char *str1, const char *str2);

char *s21_strrchr(const char *str, int c);

char *s21_strstr(const char *haystack, const char *needle);

char *s21_strtok(char *str, const char *delim);

void *s21_to_upper(const char *str);

void *s21_to_lower(const char *str);

void *s21_insert(const char *src, const char *str, s21_size_t start_index);

void *s21_trim(const char *src, const char *trim_chars);
