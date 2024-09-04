#include "s21_string.h"

s21_size_t s21_wcslen(wchar_t *str) {
  s21_size_t len = 0;
  for (; str[len]; len++)
    ;
  return len;
}

int specificator_c(
    va_list args, char *str, int n,
    symbol *symbol) {  // точность не имеет значения а ширина имеет
  char c = va_arg(args, int);
  char probel = ' ';
  if (symbol->flag_null) probel = '0';
  if (symbol->shirina != 0 && symbol->flag_minus == 0) {
    for (int i = 0; i < symbol->shirina - 1; i++) {
      str[n] = probel;
      n++;
    }
  }
  str[n] = c;
  n++;
  if (symbol->shirina != 0 && symbol->flag_minus == 1) {
    for (int i = 0; i < symbol->shirina - 1; i++) {
      str[n] = ' ';
      n++;
    }
  }
  return n;
}

int specificator_cl(va_list args, char *str, int n, symbol *symbol) {
  unsigned long int c = va_arg(args, int);
  char probel = ' ';
  if (symbol->flag_null) probel = '0';
  if (symbol->shirina != 0 && symbol->flag_minus == 0) {
    for (int i = 0; i < symbol->shirina - 1; i++) {
      str[n] = probel;
      n++;
    }
  }
  str[n] = c;
  n++;
  if (symbol->shirina != 0 && symbol->flag_minus == 1) {
    for (int i = 0; i < symbol->shirina - 1; i++) {
      str[n] = ' ';
      n++;
    }
  }
  return n;
}

int specificator_s(va_list args, char *str, int n,
                   symbol *symbol) {  //точность = сколько символов записать, а
  //ширина - сколько пробелов+симвволов
  char *s = va_arg(args, char *);
  int k = 0;
  if (s != S21_NULL)
    k = (int)s21_strlen(s);
  else
    k = 6;
  int k_prob;
  if (s == S21_NULL) {
    s = "(null)";
  }
  if (symbol->tochnost != 0 && symbol->tochnost <= k)  // для точности
  {
    k = symbol->tochnost;
  }
  char probel = ' ';
  if (symbol->flag_null) probel = '0';
  k_prob = symbol->shirina - k;
  if (symbol->shirina != 0 && symbol->flag_minus != 1) {
    k_prob = symbol->shirina - k;  // для ширины      10     20     6
    if (symbol->tochnost == -1) k_prob--;
    for (int i = 0; i < k_prob; i++) {
      str[n] = probel;
      n++;
    }
  }
  for (int i = 0; i < k; i++) {
    str[n] = s[i];
    n++;
  }
  if (symbol->shirina != 0 && symbol->flag_minus == 1) {
    // для ширины
    for (int i = 0; i < k_prob; i++) {
      str[n] = ' ';
      n++;
    }
  }
  return n;
}
int specificator_sl(va_list args, char *str, int n,
                    symbol *symbol) {  //точность = сколько символов записать, а
  //ширина - сколько пробелов+симвволов
  wchar_t *s = va_arg(args, wchar_t *);
  symbol->flag_null = 0;
  int k = (int)s21_wcslen(s);
  int k_prob = 0;
  if (symbol->tochnost != 0 && symbol->tochnost <= k)  // для точности
  {
    k = symbol->tochnost;
  }
  if (symbol->shirina != 0 && symbol->flag_minus != 1) {
    k_prob = (symbol->shirina - k);  // для ширины
    for (int i = 0; i < k_prob; i++) {
      str[n] = ' ';
      n++;
    }
  }
  for (int i = 0; i < k; i++) {
    str[n] = s[i];
    n++;
  }
  if (symbol->shirina != 0 && symbol->flag_minus == 1) {
    k_prob = abs(symbol->shirina - k);  // для ширины
    for (int i = 0; i < k_prob; i++) {
      str[i] = ' ';
      n++;
    }
  }
  return n;
}
int specificator_u(va_list args, char *str, int n,
                   symbol *symbol) {  //точность и ширина  имеет значение только
                                      //в большую сторону
  unsigned int u = va_arg(args, unsigned int);
  int mass[10] = {0};
  int k = 0;
  char probel = ' ';
  if (symbol->flag_null) probel = '0';
  for (; u >= 1; k++) {
    mass[k] = u % 10;
    u = u / 10;
  }
  if (symbol->tochnost == -1) symbol->tochnost = 0;
  int nuls = symbol->tochnost - k;
  if (symbol->tochnost <= 0) symbol->tochnost = k;
  int probels = symbol->shirina - symbol->tochnost;
  if (symbol->shirina != 0 && symbol->flag_minus == 0) {
    for (int i = 0; i < probels; i++) {
      str[n] = probel;
      n++;
    }
  }
  for (int i = 0; i < nuls; i++) {
    str[n] = '0';
    n++;
  }
  for (int i = k - 1; i >= 0; i--) {
    str[n] = mass[i] + '0';
    n++;
  }
  if (symbol->shirina != 0 && symbol->flag_minus != 0) {
    for (int i = 0; i < probels; i++) {
      str[n] = probel;
      n++;
    }
  }
  return n;
}

int specificator_ul(va_list args, char *str, int n, symbol *symbol) {
  long unsigned int u = va_arg(args, long unsigned int);
  int mass[20] = {0};
  int k = 0;
  char probel = ' ';
  if (symbol->flag_null) probel = '0';
  for (; u >= 1; k++) {
    mass[k] = u % 10;
    u = u / 10;
  }
  if (symbol->tochnost == -1) symbol->tochnost = 0;
  int nuls = symbol->tochnost - k;
  if (symbol->tochnost <= 0) symbol->tochnost = k;
  int probels = symbol->shirina - symbol->tochnost;
  if (symbol->shirina != 0 && symbol->flag_minus == 0) {
    for (int i = 0; i < probels; i++) {
      str[n] = probel;
      n++;
    }
  }
  for (int i = 0; i < nuls; i++) {
    str[n] = '0';
    n++;
  }
  for (int i = k - 1; i >= 0; i--) {
    str[n] = mass[i] + '0';
    n++;
  }
  if (symbol->shirina != 0 && symbol->flag_minus != 0) {
    for (int i = 0; i < probels; i++) {
      str[n] = probel;
      n++;
    }
  }
  return n;
}

int specificator_d(va_list args, char *str, int n, symbol *symbol) {
  int d = va_arg(args, int), mass[10] = {0}, k = 0, flag_otric = 0;
  char probel = ' ';
  if (symbol->flag_null) probel = '0';
  if (d < 0) {
    flag_otric = 1;
    d *= -1;
  }
  for (; d >= 1; k++) {
    mass[k] = d % 10;
    d = d / 10;
  }
  if (symbol->tochnost == -1) symbol->tochnost = 0;
  int nuls = symbol->tochnost - k;
  if (symbol->tochnost <= 0) symbol->tochnost = k;
  int probels = symbol->shirina - symbol->tochnost;
  if (symbol->flag_plus || flag_otric) {
    symbol->flag_probel = 0;
    probels--;
  }
  if (symbol->flag_probel) probels--;
  if (symbol->shirina != 0 && symbol->flag_minus == 0) {
    for (int i = 0; i < probels; i++) {
      str[n] = probel;
      n++;
    }
  }
  if (flag_otric) {
    str[n] = '-';
    n++;
  } else if (symbol->flag_plus == 1) {
    str[n] = '+';
    n++;
  } else if (symbol->flag_probel) {
    str[n] = ' ';
    n++;
  }
  for (int i = 0; i < nuls; i++) {
    str[n] = '0';
    n++;
  }
  for (int i = k - 1; i >= 0; i--) {
    str[n] = mass[i] + '0';
    n++;
  }
  if (symbol->shirina != 0 && symbol->flag_minus != 0) {
    for (int i = 0; i < probels; i++) {
      str[n] = probel;
      n++;
    }
  }
  return n;
}

int specificator_dl(va_list args, char *str, int n, struct symbol *symbol) {
  long int d = va_arg(args, long int);  // bool mod;
  int mass[20] = {0};
  int k = 0;
  int flag_otric = 0;
  if (d < 0) {
    flag_otric = 1;
    d *= -1;
  }
  for (; d >= 1; k++) {
    mass[k] = d % 10;
    d = d / 10;
  }
  int probels = symbol->shirina - symbol->tochnost;
  if (symbol->flag_plus || flag_otric) symbol->flag_probel = 0;
  if (symbol->flag_probel) probels--;
  if (symbol->shirina != 0) {
    if (flag_otric || symbol->flag_plus) probels -= 1;
    for (int i = 0; i < probels; i++) {
      str[n] = ' ';
      n++;
    }
  }
  if (flag_otric) {
    str[n] = '-';
    n++;
  } else if (symbol->flag_plus == 1) {
    str[n] = '+';
    n++;
  } else if (symbol->flag_probel) {
    str[n] = ' ';
    n++;
  }
  for (int i = k - 1; i >= 0; i--) {
    str[n] = mass[i] + '0';
    n++;
  }
  return n;
}

int specificator_f(va_list args, char *str, int n, symbol *symbol) {
  double f = va_arg(args, double), f_rounded = round(f);
  int k_cel = 0, m[20], flag_otric = 0, k_drob = 0;
  long int cel = (long int)f;
  if (symbol->tochnost == -1) cel = (long int)f_rounded;
  if (f < 0) {
    flag_otric = 1;
    cel *= -1;
    f *= -1;
  }
  for (; cel >= 1; k_cel++) {  // вывод целой части в массив
    m[k_cel] = cel % 10;
    cel = cel / 10;
  }
  if (symbol->tochnost > 0)
    k_drob = symbol->tochnost;
  else if (symbol->tochnost == 0)
    k_drob = 6;
  double ost = f - (long int)f;  //после запятой
  ost *= pow(10, k_drob);
  ost = round(ost) + 0.1;
  ost /= pow(10, k_drob);
  f = ost;
  int probels = symbol->shirina - (k_cel + k_drob);
  if (symbol->flag_plus || flag_otric) {
    symbol->flag_probel = 0;
    probels--;
  }
  if (symbol->flag_probel) probels--;
  if (!symbol->flag_minus) n = shifts_print(str, n, symbol, probels);
  n = flags_realization(str, n, symbol, flag_otric);
  for (int i = k_cel - 1; i >= 0; i--) {  // запись целой части в строку
    str[n] = m[i] + '0';
    n++;
  }
  if (symbol->tochnost != -1) {
    str[n] = '.';
    n++;
  }
  for (int i = 0; i < k_drob; i++) {  //запись дробной части, если есть точность
    ost = ost * 10;
    int current_num = (int)ost;
    str[n] = current_num + '0';
    ost = ost - (int)ost;
    n++;
  }
  if (symbol->flag_minus) n = shifts_print(str, n, symbol, probels);
  return n;
}

int parser_flags(char c, symbol *symbol) {
  int result = 0;
  switch (c) {
    case '+':
      symbol->flag_plus = 1;
      result = 1;
      break;
    case '-':
      symbol->flag_minus = 1;
      result = 1;
      break;
    case ' ':
      symbol->flag_probel = 1;
      result = 1;
      break;
  }
  return result;
}

int parser_shirina(char c, symbol *symbol) {
  int result = 0;
  int asci = (int)c;
  if (47 < asci && asci < 58) {  //проверка на ширину
    result = 1;
    if (symbol->shirina == 0) {
      symbol->shirina = c - '0';
      if (c == '0') symbol->flag_null = 1;
    } else {
      symbol->shirina = (symbol->shirina * 10) + (c - '0');
    }
  }
  return result;
}

int parser_tochnost(char c, symbol *symbol) {
  int result = 0;
  int asci = (int)c;
  if (48 <= asci && asci <= 57 && result == 0) {  //проверка на точность
    if (symbol->tochnost == 0)
      symbol->tochnost = c - '0';
    else {
      symbol->tochnost = ((symbol->tochnost) * 10) + (c - '0');
    }
  } else {
    if (symbol->tochnost == 0) symbol->tochnost = -1;  //для спецификатора f
    result = 1;
  }

  return result;
}

int parser_dlina(char c, symbol *symbol) {
  int result = 0;
  switch (c) {
    case 'h':
      symbol->dlina_h = 1;
      result = 1;
      break;
    case 'l':
      symbol->dlina_l = 1;
      result = 1;
      break;
  }
  return result;
}

int s21_sprintf(char *str, const char *format, ...) {
  int n = 0, i = 0;
  va_list args;
  va_start(args, format);
  while (format[i] != '\0') {
    symbol symbol = {0};
    while (format[i] != '%') {
      str[n] = format[i];
      n++;
      i++;
    }
    if ((format[i] == '%') && (format[i + 1] == '%')) {
      str[n] = format[i];
      n++;
      i++;
    } else {
      i++;
      int res = 1;
      while (res != 0) {
        res = parser_flags(format[i], &symbol);
        if (res == 1) i++;
      }
      res = 1;
      while (res != 0) {
        res = parser_shirina(format[i], &symbol);
        if (res == 1) i++;
      }
      res = 0;
      if (format[i] == '.') {
        i++;
        if (!symbol.shirina) symbol.flag_null = 0;
        while (res != 1) {
          res = parser_tochnost(format[i], &symbol);
          if (res != 1) i++;
        }
      }
      res = 1;
      while (res != 0) {
        res = parser_dlina(format[i], &symbol);
        if (res == 1) i++;
      }
      n = begin_process(format, i, args, str, n, &symbol);
    }
    if (n != -1) {
      i++;
      while (format[i] != '\0' && format[i] != '%') {
        str[n] = format[i];
        n++;
        i++;
      }
    }
  }
  str[n] = '\0';
  return n;
}

int begin_process(const char *format, int i, va_list args, char *str, int n,
                  symbol *symbol) {
  switch (format[i]) {
    case 'c':
      if (symbol->dlina_l == 1)
        n = specificator_cl(args, str, n, symbol);
      else
        n = specificator_c(args, str, n, symbol);
      i++;
      break;
    case 's':
      if (symbol->dlina_l == 1) {
        n = specificator_sl(args, str, n, symbol);
        i++;
      } else {
        n = specificator_s(args, str, n, symbol);
        i++;
      }
      break;
    case 'u':
      if (symbol->dlina_l == 1) {
        n = specificator_ul(args, str, n, symbol);
        i++;
      } else {
        n = specificator_u(args, str, n, symbol);
        i++;
      }
      break;
    case 'd':
      if (symbol->dlina_l == 1) {
        n = specificator_dl(args, str, n, symbol);
        i++;
      } else {
        n = specificator_d(args, str, n, symbol);
        i++;
      }
      break;
    case 'f':
      n = specificator_f(args, str, n, symbol);
      i++;
      break;
    default:
      n = -1;
      printf("Error");
      break;
  }
  return n;
}

int flags_realization(char *str, int n, symbol *symbol, int flag_otric) {
  if (flag_otric) {
    str[n] = '-';
    n++;
  } else if (symbol->flag_plus) {
    str[n] = '+';
    n++;
  } else if (symbol->flag_probel) {
    str[n] = ' ';
    n++;
  }
  return n;
}

int shifts_print(char *str, int n, symbol *symbol, int probels) {
  if (symbol->shirina != 0) {
    //вывод пробелов для ширины
    if (symbol->tochnost != -1) probels -= 1;
    for (int i = 0; i < probels; i++) {
      str[n] = ' ';
      n++;
    }
  }
  return n;
}
