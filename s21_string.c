#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *copy_str = (unsigned char *)str;
  void *result = S21_NULL;
  int exit = 0;
  for (s21_size_t i = 0; i < n && !exit; i++, copy_str++)
    if (*copy_str == c) {
      result = copy_str;
      exit = 1;
    }
  return result;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result = 0, exit = 0;
  unsigned char *str1_copy = (unsigned char *)str1,
                *str2_copy = (unsigned char *)str2;
  for (s21_size_t i = 0; i < n && !exit; i++, str1_copy++, str2_copy++)
    if (*str1_copy != *str2_copy) {
      result = *str1_copy - *str2_copy;
      exit = 1;
    }
  return result;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *copy_src = (unsigned char *)src,
                *copy_dest = (unsigned char *)dest;
  for (s21_size_t i = 0; i < n; i++) *copy_dest++ = *copy_src++;
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  char *res;
  int k = (int)n;
  res = str;
  for (int i = 0; i < k; i++) {
    res[i] = (char)c;
  }
  return (!str) ? S21_NULL : str;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  int i = 0;
  int f = (int)n;
  while (dest[i] != '\0') i++;
  int j = 0;
  for (int k = i; k < i + f; k++) {
    dest[k] = src[j];
    j++;
  }
  dest[i + j] = '\0';
  return dest;
}

char *s21_strchr(const char *str, int c) {
  while (*str != '\0' && *str != c) {
    str++;
  }

  return *str == c ? (char *)str : S21_NULL;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;
  s21_size_t i = 0;
  while (i < n && result == 0) {
    int ch1 = (int)(str1[i]);
    int ch2 = (int)(str2[i]);
    result = ch1 - ch2;
    i++;
  }
  return result;
}

char *s21_strcpy(char *dest, const char *src) {
  char *ret = dest;
  while ((*dest++ = *src++) != '\0')
    ;
  return ret;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i;
  for (i = 0; i < n; i++) {
    dest[i] = src[i];
  }
  for (; i < n; i++) {
    dest[i] = '\0';
  }
  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  int found = 0;
  int count = 0;
  for (s21_size_t i = 0; i < s21_strlen(str1); i++) {
    for (s21_size_t j = 0; j < s21_strlen(str2); j++) {
      if (str1[i] == str2[j]) {
        found = 1;
      }
    }
    if (found == 0) {
      count++;
    }
  }

  return count;
}

char *s21_strerror(int errnum) {
  static char err[1024];
  char *ERR[] = LIST_ERR;
  if (errnum < ERR_MIN || errnum > ERR_MAX) {
    s21_sprintf(err, ERROR, errnum);
  } else {
    s21_strcpy(err, ERR[errnum]);
  }
  return err;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;
  for (; str[len]; len++)
    ;
  return len;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *s1 = (char *)str1;
  char *s2 = (char *)str2;
  int flag = 0, i = 0;
  while (*s1 != '\0' && flag == 0) {
    i = 0;
    while (*(s2 + i) && flag == 0) {
      if (*s1 == *(s2 + i)) {
        flag = 1;
      }
      i++;
    }
    s1++;
  }
  return flag ? s1 - 1 : S21_NULL;
}

char *s21_strrchr(const char *str, int c) {
  char *s = (char *)str;
  char *buf = S21_NULL;
  int i = 0;
  if (c == '\0') buf = "";
  while (s[i] != '\0' && buf == S21_NULL) {
    if (s[i] == c) {
      buf = s;
    }
    s++;
  }
  return buf;
}
char *s21_strstr(const char *haystack, const char *needle) {
  char *s = (char *)haystack;
  char *buf = S21_NULL;
  char *buf2 = S21_NULL;
  int flag = 1;
  if (needle[0] == '\0') {
    buf = s;
    flag = 0;
  }
  while (*s != '\0' && flag) {
    if (buf2 != S21_NULL)
      s = buf2;
    else {
      while (*s != needle[0] && *s != '\0') s++;
    }
    if (*s == needle[0]) {
      buf = s;
      int i = 1;
      s++;
      while (needle[i] != '\0' && needle[i] == *s && *s != '\0') {
        if (*s == needle[0]) {
          buf2 = s;
        }
        s++;
        i++;
      }
      if (needle[i] == '\0')
        flag = 0;
      else
        buf = S21_NULL;
    }
  }
  return buf;
}

char *s21_strtok(char *str, const char *delim) {
  static char *str1 = S21_NULL;
  char *result = S21_NULL;
  int flag_delim = 0;
  if (str != S21_NULL) {
    str1 = str;
  }

  int flag_str = 0;
  int flag_end_str = 0;
  while (*str1 != '\0' && !flag_str) {
    int flag1 = 0;
    flag_delim = 0;

    for (s21_size_t i = 0; delim[i] != '\0' && !flag1; i++) {
      if (*str1 == delim[i]) {
        flag_delim = 1;
        str1++;
        flag1 = 1;
      }
    }

    if (!flag_delim) {
      flag_str = 1;
    }
  }

  if (*str1 == '\0') {
    flag_end_str = 1;
  } else {
    result = str1;

    while (*str1 != '\0' && !flag_end_str) {
      flag_str = 0;
      flag_end_str = 0;
      int flag_delim = 0;

      for (s21_size_t i = 0; delim[i] != '\0' && !flag_str; i++) {
        if (*str1 == delim[i]) {
          flag_delim = 1;
          flag_str = 1;
        }
      }

      if (flag_delim) {
        *str1 = '\0';
        str1++;
        flag_end_str = 1;
      }
      if (!flag_end_str) str1++;
    }
  }

  return result;
}

void *s21_to_upper(const char *str) {
  char *stroka = S21_NULL;
  if (str != S21_NULL) {
    s21_size_t len_str = s21_strlen(str);
    if (*str != 0) {
      stroka = (char *)malloc((len_str + 1) * sizeof(char));
      for (s21_size_t i = 0; i < len_str; i++) {
        if (str[i] > 0x60 && str[i] < 0x7b) {
          stroka[i] = str[i] - 32;
        } else {
          stroka[i] = str[i];
        }
      }

    } else
      stroka = "";
  } else
    stroka = S21_NULL;
  return stroka;
}

void *s21_to_lower(const char *str) {
  char *stroka = S21_NULL;
  if (str != S21_NULL) {
    s21_size_t len_str = s21_strlen(str);
    if (*str != 0) {
      stroka = (char *)malloc((len_str + 1) * sizeof(char));
      for (s21_size_t i = 0; i < len_str; i++) {
        if (str[i] > 0x40 && str[i] < 0x5B) {
          stroka[i] = str[i] + 32;
        } else {
          stroka[i] = str[i];
        }
      }
    } else
      stroka = "";
  }
  return stroka;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *stroka = S21_NULL;
  s21_size_t len_str = 0;
  s21_size_t len_src = 0;
  if (src != 0 && str != 0) {
    len_src = s21_strlen(src);
    len_str = s21_strlen(str);
  }
  if (start_index < len_src && (long int)start_index >= 0) {
    stroka = (char *)malloc((len_str + len_src + 1) * sizeof(char));
    for (s21_size_t i = 0, j = 0, t = 0; i < len_src + len_src; i++) {
      stroka[i] = src[i];
      if (i == start_index || (i > start_index && j < len_str)) {
        stroka[i] = str[j];
        j++;
      } else {
        stroka[i] = src[t];
        t++;
      }
    }
  }
  return stroka;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *stroka = S21_NULL;

  if (src != S21_NULL) {
    int start = 0, end = s21_strlen(src) - 1;
    while (src[start] != '\0' && s21_strchr(trim_chars, src[start]) != S21_NULL)
      start++;
    while (end >= start && s21_strchr(trim_chars, src[end]) != S21_NULL) end--;
    int length = end - start + 1;
    stroka = (char *)malloc((length + 1) * sizeof(char));
    s21_strncpy(stroka, src + start, length);
    stroka[length] = '\0';
  }

  return stroka;
}
