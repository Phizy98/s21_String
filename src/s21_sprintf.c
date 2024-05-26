#include "s21_string.h"

// main only for manual testing (to visualize original work VS out), delete it
// later...
// int main () {

//     // char *text = calloc(MAX_STRING_LEN, sizeof(char));
//     // unsigned int a = 1000000000000;
//     // s21_int_to_string(text, 1, 10, LOW_CASE);
//     // printf("INPUT: %d\nOriginal:\n%u\nOur output:\n%s\n\n\n", a, a, text);

//     char *str = calloc(MAX_STRING_LEN, sizeof(char));
//     char *original_str = calloc(MAX_STRING_LEN, sizeof(char));
//     //char *format = calloc(MAX_STRING_LEN, sizeof(char));

//   //   char str1[100] = "";
//   // char str2[100] = "";
//   // char *str3 = "%20.20u";
//   // unsigned int val1 = -123;
//   // //int e = 12368598;

//   //   //char *format = "fin%%yj.321Ldaboba::::%-+ 20.5ld:::lalala"; // block
//   //for changes !!!!!!!

//   //    int original_rez = sprintf(str1, str3, val1);        //
//   //   int our_rez = s21_sprintf(str2, str3, val1);                //

//   char str1[512]={'\0'};
//   char str2[512]={'\0'};

//       //char *format = "%.17LE";
//       //long double val = 4134121;

//   char *format = "%10f";
//   double val = NAN;

//   int our_rez = s21_sprintf(str1, format, val);
//   int original_rez = sprintf(str2, format, val);

//     printf("our str:\n%s()\n", str1);

//     printf("original str:\n%s()\n", str2);

//     printf("original rez = %d     our rez = %d\n", original_rez, our_rez);
//     //printf("original rez = %d , our rez = %d\n", rez, our_rez);
//     //printf("my output:\n%s\n", str);
//     free(str);
//     //free(format);
//     free(original_str);

//     return 0;
// }

int s21_sprintf(char *str, const char *format, ...) {
  struct variables options = {"-+ #0", "hlL", "cdieEfgGosuxXp%", "aaaaa", 0, -2,
                              '\0',    '\0'};

  va_list param;            // creat pointer to optional parameter
  va_start(param, format);  // to find the beginning of optional parameters

  char *output_string_pointer = str;
  char **p_output_string_pointer = &output_string_pointer;
  char *format_pointer = (char *)format;
  char *c_copy = s21_NULL;

  // c - pointer to first character of the format string. Then move the pointer,
  // until the end
  for (char *c = format_pointer; *c; c++) {
    // printf("stroks c = %s\n", c);
    // printf("c start = %c\n", *c);
    // simple text in str
    if (*c != '%') {
      *output_string_pointer = *c;
      output_string_pointer++;
      // printf("c finish1 = %c\n", *c);
      // printf("*c = %c here STR:%s()\n",*c, str);
      // printf("if output_string_pointer = %d\n", output_string_pointer);
      continue;
    }
    // if symbol is '%' take the next symbol and do operation for specifires
    else {
      c++;
      if (*c == '%') {
        *output_string_pointer = *c;
        output_string_pointer++;
      } else {
        c = c + s21_specifire(c, param, options, c_copy, output_string_pointer,
                              p_output_string_pointer, str);
        // printf("NOW STR:%s()\n", str);
        // printf("else output_string_pointer = %d\n", output_string_pointer);
        // options.flag = "aaaaa";
        for (int h = 0; h < 5; h++) {
          options.flag[h] = 'a';
        }

        options.width = 0;
        options.precision = -2;
        options.size = '\0';
        options.type = '\0';
      }
    }
    // printf("c finish2 = %c\n", *c);
  }

  // printf(" flag: %c   width: %d  precision: %d   size: %c  type:  %c\n",
  // options.flag[0], options.width, options.precision, options.size,
  // options.type);

  va_end(param);

  // printf("output = %d", strlen(str));
  // printf("STR: %s\n", str);
  return s21_strlen(str);
  // return s21_strlen(str);
}

int s21_specifire(char *c, va_list param, struct variables options,
                  char *c_copy, char *output_string_pointer,
                  char **p_output_string_pointer, char *str) {
  int flag_error = 0, str_specifire_len = 0;
  char str_specifire[MAX_STRING_LEN] = {'\0'};
  c_copy = c;

  while (!s21_is_in_str(*c_copy, options.types) && *c_copy != '\0') {
    str_specifire[str_specifire_len] = *c_copy;
    str_specifire_len++;
    c_copy++;
  }

  // printf("specifire:\n%s\n", str_specifire);

  int indicator = 0, i = 0;

  int flag_break = 0;
  if (indicator == 0) {  // check is it flag
    if (str_specifire[i] == '\0')
      flag_break = 1;
    else {
      indicator++;
      while (s21_is_in_str(str_specifire[i], options.flags) == 1) {
        if (str_specifire[i] == '-') options.flag[0] = '-';
        if (str_specifire[i] == '+') options.flag[1] = '+';
        if (str_specifire[i] == ' ') options.flag[2] = ' ';
        if (str_specifire[i] == '#') options.flag[3] = '#';
        if (str_specifire[i] == '0') options.flag[4] = '0';
        // options.flag = str_specifire[i];
        i++;
        // break;
      }
    }
  }

  if (indicator == 1 && flag_break == 0) {  // check is it width
    if (str_specifire[i] == '\0')
      flag_break = 1;
    else {
      indicator++;
      if (str_specifire[i] == '*') {
        options.width = -1;
        i++;
      } else if (str_specifire[i] >= 48 &&
                 str_specifire[i] <= 57) {  // if number go along the line until
                                            // the numbers ends
        int number = 0;

        while (str_specifire[i] >= 48 && str_specifire[i] <= 57) {
          number = number * 10 + (str_specifire[i] - 48);
          i++;
        }
        i--;
        options.width = number;
        i++;
      }
    }
  }

  if (indicator == 2 && flag_break == 0) {  // check is it presidion
    if (str_specifire[i] == '\0')
      flag_break = 1;
    else {
      // printf("case 2 symbol = %c\n", str_specifire[i]);
      indicator++;

      if (str_specifire[i] == '.') {
        i++;

        if (str_specifire[i] == '*') {
          options.precision = -1;
          i++;
        } else if (str_specifire[i] >= 48 &&
                   str_specifire[i] <= 57) {  // if number go along the line
                                              // until the numbers ends
          int number = 0;

          while (str_specifire[i] >= 48 && str_specifire[i] <= 57) {
            number = number * 10 + (str_specifire[i] - 48);
            i++;
          }
          i--;
          options.precision = number;
          i++;
        }
        ///////////////
        else {
          options.precision = 0;
        }
        ////////////////
      }
    }
  }

  if (indicator == 3 && flag_break == 0) {  // check is it width
    if (str_specifire[i] == '\0')
      flag_break = 1;
    else {
      indicator++;
      if (s21_is_in_str(str_specifire[i], options.sizes)) {
        options.size = str_specifire[i];
        i++;
        flag_break = 1;
      }
    }
  }

  if (flag_break == 0) {
    flag_error = 1;
  }

  /////////////////////

  // printf("*c_copy = %c, flag_error = %d", *c_copy, flag_error);
  if (flag_error == 0 && s21_is_in_str(*c_copy, options.types))
    options.type = *c_copy;

  if (flag_error == 1) {
    c_copy = &str_specifire[i];
    /*
    *output_string_pointer = '%';
    output_string_pointer++; */
    *output_string_pointer = str_specifire[i];
    output_string_pointer++;

    *p_output_string_pointer = output_string_pointer;
    /*
    while (i <= strlen(str_specifire)-1) {
    *output_string_pointer = str_specifire[i];
    output_string_pointer++;
    i++;
    //output_string_pointer++;
    }
    printf("ERRR\n");
    printf("output string: %s\n", str); */
  }

  // printf(" flag: %c   width: %d  precision: %d   size: %c  type:  %c\n",
  // options.flag[2], options.width, options.precision, options.size,
  // options.type);

  // if (flag_error == 0)
  // result = c_copy;

  // printf(param);
  s21_processing(param, options, output_string_pointer, p_output_string_pointer,
                 str);

  return i;
}

void s21_processing(va_list param, struct variables options,
                    char *output_string_pointer, char **p_output_string_pointer,
                    char *str) {
  // if * in width or precision
  if (options.width == -1) {
    options.width = va_arg(param, int);
  }
  if (options.precision == -1) {
    options.precision = va_arg(param, int);
  }

  if (options.type == 'd' || options.type == 'i') {
    if (options.size == '\0') {
      int arg = va_arg(param, int);  // type(d,i) for int DONE
      // printf("I'm in s21_processing\n");
      *p_output_string_pointer =
          s21_type_d_i_for_int(arg, options, output_string_pointer);
      // printf("NOW STR:%s()\n", str);
    } else if (options.size == 'h') {
      // printf("JJJJJJJJJJJJ\n");
      short arg = (short)va_arg(param, int);  // type(d,i) for short int *DONE
      // printf("LLLLL %hd\n", arg);
      *p_output_string_pointer =
          s21_type_d_i_for_int((int)arg, options, output_string_pointer);
    } else if (options.size == 'l') {
      long int arg = va_arg(param, long int);  // type(d,i) for long int DONE
      *p_output_string_pointer =
          s21_type_d_i_for_long_int(arg, options, output_string_pointer);
    } else {
      fprintf(stderr, "INVALID VALIDATION\n");
    }
  }

  if (options.type == 'u' || options.type == 'o' || options.type == 'x' ||
      options.type == 'X') {
    if (options.size == '\0') {
      unsigned int arg =
          va_arg(param, unsigned int);  // type(u,o,x,X) for unsigned int DONE
      *p_output_string_pointer =
          s21_type_d_i_for_int(arg, options, output_string_pointer);
    } else if (options.size == 'h') {
      unsigned short int arg = (unsigned short int)va_arg(
          param, unsigned int);  // type(u,o,x,X) for unsigned int DONE
      *p_output_string_pointer =
          s21_type_d_i_for_int(arg, options, output_string_pointer);
    } else if (options.size == 'l') {
      unsigned long int arg = va_arg(
          param,
          unsigned long int);  // type(u,o,x,X) for unsigned long int DONE
      *p_output_string_pointer =
          s21_type_d_i_for_long_int(arg, options, output_string_pointer);
    } else {
      fprintf(stderr, "INVALID VALIDATION\n");
    }
  }

  if (options.type == 'f' || options.type == 'e' || options.type == 'E' ||
      options.type == 'g' || options.type == 'G') {
    if (options.size == '\0' || options.size == 'h' || options.size == 'l') {
      double arg = va_arg(param, double);  // type(f,e,E,g,G) for double WORK
      // printf("yyyy arg = %f\n", arg);
      *p_output_string_pointer =
          s21_for_double(arg, options, output_string_pointer);
    } else if (options.size == 'L') {
      long double arg =
          va_arg(param, long double);  // type(f,e,E,g,G) for long double WORK
      *p_output_string_pointer =
          s21_for_long_double(arg, options, output_string_pointer);
    } else {
      fprintf(stderr, "INVALID VALIDATION\n");
    }
  }

  if (options.type == 'c') {
    if (options.size == '\0' || options.size == 'l' || options.size == 'h' ||
        options.size == 'L') {
      int arg = va_arg(param, int);  // type(c) for int DONE
      *p_output_string_pointer =
          s21_type_c_for_int(arg, options, output_string_pointer);
    } else if (options.size == 'l') {
      // wint_t arg = va_arg(param, wint_t);   // type(c) for wint_t    (with
      // #include <wchar.h>)
    } else {
      fprintf(stderr, "INVALID VALIDATION\n");
    }
  }

  if (options.type == 's') {
    if (options.size == '\0' || options.size == 'h' || options.size == 'L') {
      char *arg = va_arg(param, char *);  // type(s) for char* DONE
      *p_output_string_pointer =
          s21_type_s_for_char(arg, options, output_string_pointer);
    } else {
      fprintf(stderr, "INVALID VALIDATION\n");
    }
  }

  if (options.type == 'p') {
    if (options.size == '\0') {
      void *arg = va_arg(param, void *);  // type(p) for void*

      *p_output_string_pointer =
          s21_type_p_for_void(arg, options, output_string_pointer);
    } else {
      fprintf(stderr, "INVALID VALIDATION\n");
    }
  }

  // if (options.type == 'n') {
  //   int *arg = va_arg(param, int *);
  //   *arg = s21_strlen(str);
  // }
  if (str == s21_NULL) {
    ;
  }

  if (options.type == '%') {
    // put % in str
  }
}

int s21_is_in_str(char symbol, char str[]) {
  int counter = 0;
  int result = 0;
  while (str[counter] != '\0') {
    if (symbol == str[counter]) {
      result = 1;
      break;
    }
    counter++;
  }

  return result;
}

// take argument and make a variable "arg" of the corect type

char *s21_type_d_i_for_int(unsigned int arg, struct variables options,
                           char *output_string_pointer) {
  int hight = LOW_CASE;
  if (options.type == 'X') hight = HIGHT_CASE;
  int base = 10;

  if (options.type == 'o')
    base = 8;
  else if (options.type == 'X' || options.type == 'x')
    base = 16;
  else if (options.type == 'u')
    base = 0;

  char *dest = calloc(MAX_STRING_LEN, sizeof(char));

  dest = s21_int_to_string(dest, arg, base, hight);

  // for flag # and type o

  if (options.flag[3] == '#' && options.type == 'o' && arg != 0) {
    char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
    s21_memcpy(dest_copy, dest, s21_strlen(dest));
    dest[0] = '0';
    for (int i = 0; (s21_size_t int)i < s21_strlen(dest_copy); i++) {
      dest[i + 1] = dest_copy[i];
    }
    free(dest_copy);
  }

  //            precision
  if (options.precision == 0 && arg == 0) {
    dest[0] = '\0';
  } else if ((int)s21_strlen(dest) < options.precision) {
    char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
    s21_memcpy(dest_copy, dest, s21_strlen(dest));
    // printf("dest_copy:%s()\n", dest_copy);
    int count_of_zero = options.precision - s21_strlen(dest);
    int i = 0;

    for (; i < count_of_zero; i++) {
      dest[i] = '0';
    }

    // s21_insert(dest, dest_copy, i)    start    here
    int n = 0;
    for (; i < options.precision; i++) {
      dest[i] = dest_copy[n];
      n++;
    }
    // s21_insert(dest, dest_copy, i)     finish    here
    free(dest_copy);
  }
  // printf("dest:%s()\n", dest);

  if ((options.flag[1] == '+' || options.flag[2] == ' ') &&
      options.type != 'u') {
    char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
    s21_memcpy(dest_copy, dest, s21_strlen(dest));
    // printf("dest_copy with +:%s\n", dest_copy);
    if ((int)arg >= 0) {
      if (options.flag[1] == '+')
        dest[0] = '+';
      else
        dest[0] = ' ';

      for (int i = 0; (s21_size_t int)i < s21_strlen(dest_copy); i++) {
        dest[i + 1] = dest_copy[i];
      }
    }

    // printf("dest with +:%s\n", dest);

    free(dest_copy);
  }

  // for flag # and type x/X

  if (options.flag[3] == '#' && (options.type == 'X' || options.type == 'x') &&
      arg != 0) {
    char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
    s21_memcpy(dest_copy, dest, s21_strlen(dest));
    dest[0] = '0';
    if (options.type == 'x')
      dest[1] = 'x';
    else if (options.type == 'X')
      dest[1] = 'X';

    for (int i = 0; (s21_size_t int)i < s21_strlen(dest_copy); i++) {
      dest[i + 2] = dest_copy[i];
    }
    free(dest_copy);
  }

  // width

  if (s21_strlen(dest) < (s21_size_t int)options.width) {
    char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
    s21_memcpy(dest_copy, dest, s21_strlen(dest));
    // printf("dest_copy:%s()\n", dest_copy);
    int count_of_space = options.width - s21_strlen(dest);
    int i = 0;
    int step = 0;
    if (options.flag[0] == '-') step = s21_strlen(dest);

    for (; i < count_of_space; i++) {
      if (options.flag[4] == '0')
        dest[i + step] = '0';
      else
        dest[i + step] = ' ';
    }
    // printf("now dest:%s()\n", dest);

    // s21_insert(dest, dest_copy, i)    start    here
    if (options.flag[0] != '-') {
      int n = 0;
      for (; i < options.width; i++) {
        dest[i] = dest_copy[n];
        n++;
      }
    }
    // s21_insert(dest, dest_copy, i)     finish    here
    free(dest_copy);
  }

  // printf("final dest:%s()\n", dest);

  for (int i = 0; (s21_size_t int)i < s21_strlen(dest); i++) {
    *output_string_pointer = dest[i];
    output_string_pointer++;

    //*p_output_string_pointer++;
    // printf("output_string_pointer = %d\n", output_string_pointer);
  }

  free(dest);

  return output_string_pointer;
}

// char *s21_type_d_i_for_short_int (unsigned short int arg, struct variables
// options, char *output_string_pointer) {
//     int hight = LOW_CASE;
//     if (options.type == 'X') hight = HIGHT_CASE;
//     int base = 10;
//     if (options.type == 'o') base = 8;
//     else if (options.type == 'X' || options.type == 'x') base = 16;

//     char * dest = calloc(MAX_STRING_LEN, sizeof(char));

//     dest = s21_int_to_string(dest, arg, base, hight);

//     // if (arg < 0) {
//     //     for (int i = 0; i < s21_strlen(dest); i++) {
//     //         dest[i] = dest[i+1];
//     //     }
//     // }

//     //            precision
//     if (options.precision == 0 && arg == 0) {
//         dest[0] = '\0';
//     }
//     else if ((int)s21_strlen(dest) < options.precision) {
//         char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
//         s21_memcpy(dest_copy, dest, s21_strlen(dest));
//         //printf("dest_copy:%s()\n", dest_copy);
//         int count_of_zero = options.precision - s21_strlen(dest);
//         int i = 0;

//         for (; i < count_of_zero; i++) {
//             dest[i] = '0';
//         }

//         //s21_insert(dest, dest_copy, i)    start    here
//         int n = 0;
//         for (; i < options.precision; i++) {
//             dest[i] = dest_copy[n];
//             n++;
//         }
//         //s21_insert(dest, dest_copy, i)     finish    here
//         free(dest_copy);
//     }
//     //printf("dest:%s()\n", dest);

//         if ((options.flag[1] == '+' || options.flag[2] == ' ') &&
//         options.type != 'u') { char *dest_copy = calloc(MAX_STRING_LEN,
//         sizeof(char)); s21_memcpy(dest_copy, dest, s21_strlen(dest));
//         //printf("dest_copy with +:%s\n", dest_copy);
//         if((short int)arg >= 0) {
//                 if (options.flag[1] == '+')
//                     dest[0] = '+';
//                 else
//                     dest[0] = ' ';

//                 for (int i = 0; (s21_size_t int)i < s21_strlen(dest_copy);
//                 i++) {
//                     dest[i+1] = dest_copy[i];
//                 }
//         }

//         //printf("dest with +:%s\n", dest);

//         free(dest_copy);
//     }

//     // width

//     if (s21_strlen(dest) < (s21_size_t int)options.width) {
//         char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
//         s21_memcpy(dest_copy, dest, s21_strlen(dest));
//         //printf("dest_copy:%s()\n", dest_copy);
//         int count_of_space = options.width - s21_strlen(dest);
//         int i = 0;
//         int step = 0;
//         if (options.flag[0] == '-')
//             step = s21_strlen(dest);

//         for (; i < count_of_space; i++) {
//             if (options.flag[4] == '0')
//                 dest[i+step] = '0';
//             else
//                 dest[i+step] = ' ';
//         }
//         //printf("now dest:%s()\n", dest);

//         //s21_insert(dest, dest_copy, i)    start    here
//         if (options.flag[0] != '-') {
//         int n = 0;
//         for (; i < options.width; i++) {
//             dest[i] = dest_copy[n];
//             n++;
//         }
//         }
//         //s21_insert(dest, dest_copy, i)     finish    here
//         free(dest_copy);
//     }

//     //printf("final dest:%s()\n", dest);

//     for (int i = 0; (s21_size_t int)i < s21_strlen(dest); i++) {
//     *output_string_pointer = dest[i];
//     output_string_pointer++;

//     //*p_output_string_pointer++;
//     //printf("output_string_pointer = %d\n", output_string_pointer);
//     }

//     free(dest);

//     return output_string_pointer;
// }

char *s21_type_d_i_for_long_int(unsigned long int arg, struct variables options,
                                char *output_string_pointer) {
  int hight = LOW_CASE;
  if (options.type == 'X') hight = HIGHT_CASE;
  int base = 10;

  if (options.type == 'o')
    base = 8;
  else if (options.type == 'X' || options.type == 'x')
    base = 16;
  else if (options.type == 'u')
    base = 0;

  char *dest = calloc(MAX_STRING_LEN, sizeof(char));

  dest = s21_long_to_string(dest, arg, base, hight);

  // for flag # and type o

  if (options.flag[3] == '#' && options.type == 'o' && arg != 0) {
    char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
    s21_memcpy(dest_copy, dest, s21_strlen(dest));
    dest[0] = '0';
    for (int i = 0; (s21_size_t int)i < s21_strlen(dest_copy); i++) {
      dest[i + 1] = dest_copy[i];
    }
    free(dest_copy);
  }

  //            precision
  if (options.precision == 0 && arg == 0) {
    dest[0] = '\0';
  } else if ((int)s21_strlen(dest) < options.precision) {
    char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
    s21_memcpy(dest_copy, dest, s21_strlen(dest));
    // printf("dest_copy:%s()\n", dest_copy);
    int count_of_zero = options.precision - s21_strlen(dest);
    int i = 0;

    for (; i < count_of_zero; i++) {
      dest[i] = '0';
    }

    // s21_insert(dest, dest_copy, i)    start    here
    int n = 0;
    for (; i < options.precision; i++) {
      dest[i] = dest_copy[n];
      n++;
    }
    // s21_insert(dest, dest_copy, i)     finish    here
    free(dest_copy);
  }
  // printf("dest:%s()\n", dest);

  if ((options.flag[1] == '+' || options.flag[2] == ' ') &&
      options.type != 'u') {
    char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
    s21_memcpy(dest_copy, dest, s21_strlen(dest));
    // printf("dest_copy with +:%s\n", dest_copy);
    if ((long int)arg >= 0) {
      if (options.flag[1] == '+')
        dest[0] = '+';
      else
        dest[0] = ' ';

      for (int i = 0; (s21_size_t int)i < s21_strlen(dest_copy); i++) {
        dest[i + 1] = dest_copy[i];
      }
    }

    // printf("dest with +:%s\n", dest);

    free(dest_copy);
  }

  // for flag # and type x/X

  if (options.flag[3] == '#' && (options.type == 'X' || options.type == 'x') &&
      arg != 0) {
    char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
    s21_memcpy(dest_copy, dest, s21_strlen(dest));
    dest[0] = '0';
    if (options.type == 'x')
      dest[1] = 'x';
    else if (options.type == 'X')
      dest[1] = 'X';

    for (int i = 0; (s21_size_t int)i < s21_strlen(dest_copy); i++) {
      dest[i + 2] = dest_copy[i];
    }
    free(dest_copy);
  }

  // width

  if (s21_strlen(dest) < (s21_size_t int)options.width) {
    char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
    s21_memcpy(dest_copy, dest, s21_strlen(dest));
    // printf("dest_copy:%s()\n", dest_copy);
    int count_of_space = options.width - s21_strlen(dest);
    int i = 0;
    int step = 0;
    if (options.flag[0] == '-') step = s21_strlen(dest);

    for (; i < count_of_space; i++) {
      if (options.flag[4] == '0')
        dest[i + step] = '0';
      else
        dest[i + step] = ' ';
    }
    // printf("now dest:%s()\n", dest);

    // s21_insert(dest, dest_copy, i)    start    here
    if (options.flag[0] != '-') {
      int n = 0;
      for (; i < options.width; i++) {
        dest[i] = dest_copy[n];
        n++;
      }
    }
    // s21_insert(dest, dest_copy, i)     finish    here
    free(dest_copy);
  }

  // printf("final dest:%s()\n", dest);

  for (int i = 0; (s21_size_t int)i < s21_strlen(dest); i++) {
    *output_string_pointer = dest[i];
    output_string_pointer++;

    //*p_output_string_pointer++;
    // printf("output_string_pointer = %d\n", output_string_pointer);
  }

  free(dest);

  return output_string_pointer;
}

char *s21_for_double(double arg, struct variables options,
                     char *output_string_pointer) {
  // printf("yyyy arg = %f\n", arg);
  int flag_free = 1;
  if (options.precision == -2) options.precision = 6;
  int is_sharp = 0;
  if (options.flag[3] == '#') is_sharp = 1;
  char *dest = calloc(MAX_STRING_LEN, sizeof(char));
  char *dest_1 = calloc(MAX_STRING_LEN, sizeof(char));
  if (arg == INFINITY || arg == -INFINITY) {
    dest[0] = 'i';
    dest[1] = 'n';
    dest[2] = 'f';
  } else if (isnan(arg)) {
    dest[0] = 'n';
    dest[1] = 'a';
    dest[2] = 'n';
  } else {
    if (options.type == 'f') {
      // printf("I'm here\n");
      s21_doubleToString(arg, dest, options.precision, is_sharp);
      // printf("00 dest: %s\n", dest);
    } else if (options.type == 'e') {
      dest = s21_double_to_notation(dest, arg, options.precision, LOW_CASE);
    } else if (options.type == 'E') {
      dest = s21_double_to_notation(dest, arg, options.precision, HIGHT_CASE);
    } else if (options.type == 'g') {
      // printf("yy arg = %f\n", arg);
      dest =
          s21_flag_g_double(dest, arg, options.precision, is_sharp, LOW_CASE);
    } else if (options.type == 'G') {
      dest =
          s21_flag_g_double(dest, arg, options.precision, is_sharp, HIGHT_CASE);
    }
    // something for G and g
    if (dest == s21_NULL) {
      dest = dest_1;
      flag_free = 0;
    }

    if (arg < 0) {
      for (int i = 0; (s21_size_t int)i < s21_strlen(dest); i++) {
        dest[i] = dest[i + 1];
      }
    }
  }

  //            precision

  if ((options.flag[1] == '+' || options.flag[2] == ' ') && arg >= 0) {
    char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
    s21_memcpy(dest_copy, dest, s21_strlen(dest));
    // printf("dest_copy with +:%s\n", dest_copy);
    if (arg >= 0) {
      if (options.flag[1] == '+')
        dest[0] = '+';
      else
        dest[0] = ' ';

      for (int i = 0; (s21_size_t int)i < s21_strlen(dest_copy); i++) {
        dest[i + 1] = dest_copy[i];
      }
    }

    // printf("dest with +:%s\n", dest);

    free(dest_copy);
  } else if (arg < 0) {
    dest[s21_strlen(dest)] = '\0';
    for (int i = s21_strlen(dest); i > 0; i--) {
      dest[i] = dest[i - 1];
    }
    dest[0] = '-';
  }

  // width

  if (s21_strlen(dest) < (s21_size_t int)options.width) {
    char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
    s21_memcpy(dest_copy, dest, s21_strlen(dest));
    // printf("dest_copy:%s()\n", dest_copy);
    int count_of_space = options.width - s21_strlen(dest);
    int i = 0;
    int step = 0;
    if (options.flag[0] == '-') step = s21_strlen(dest);

    for (; i < count_of_space; i++) {
      if (options.flag[4] == '0')
        dest[i + step] = '0';
      else
        dest[i + step] = ' ';
    }
    // printf("now dest:%s()\n", dest);

    // s21_insert(dest, dest_copy, i)    start    here
    if (options.flag[0] != '-') {
      int n = 0;
      for (; i < options.width; i++) {
        dest[i] = dest_copy[n];
        n++;
      }
    }
    // s21_insert(dest, dest_copy, i)     finish    here
    free(dest_copy);
  }

  // printf("final dest:%s()\n", dest);

  for (int i = 0; (s21_size_t int)i < s21_strlen(dest); i++) {
    *output_string_pointer = dest[i];
    output_string_pointer++;

    //*p_output_string_pointer++;
    // printf("output_string_pointer = %d\n", output_string_pointer);
  }
  if (flag_free == 1) {
    free(dest);
  }
  free(dest_1);

  return output_string_pointer;
}

char *s21_for_long_double(long double arg, struct variables options,
                          char *output_string_pointer) {
  int flag_free = 1;
  if (options.precision == -2) options.precision = 6;
  int is_sharp = 0;
  if (options.flag[3] == '#') is_sharp = 1;

  char *dest = calloc(MAX_STRING_LEN, sizeof(char));
  char *dest_1 = calloc(MAX_STRING_LEN, sizeof(char));

  if (arg == INFINITY || arg == -INFINITY) {
    dest[0] = 'i';
    dest[1] = 'n';
    dest[2] = 'f';
  } else if (isnan(arg)) {
    dest[0] = 'n';
    dest[1] = 'a';
    dest[2] = 'n';
  } else {
    if (options.type == 'f') {
      s21_long_doubleToString(arg, dest, options.precision, is_sharp);
    } else if (options.type == 'e') {
      dest = s21_double_to_notation(dest, arg, options.precision, LOW_CASE);
    } else if (options.type == 'E') {
      dest = s21_double_to_notation(dest, arg, options.precision, HIGHT_CASE);
    } else if (options.type == 'g') {
      // printf("yy arg = %f\n", arg);
      dest = s21_flag_g_long_double(dest, arg, options.precision, is_sharp,
                                    LOW_CASE);
    } else if (options.type == 'G') {
      dest = s21_flag_g_long_double(dest, arg, options.precision, is_sharp,
                                    HIGHT_CASE);
    }

    if (dest == s21_NULL) {
      dest = dest_1;
      flag_free = 0;
    }

    if (arg < 0) {
      for (int i = 0; (s21_size_t int)i < s21_strlen(dest); i++) {
        dest[i] = dest[i + 1];
      }
    }
  }

  //            precision

  if ((options.flag[1] == '+' || options.flag[2] == ' ') && arg >= 0) {
    char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
    s21_memcpy(dest_copy, dest, s21_strlen(dest));
    // printf("dest_copy with +:%s\n", dest_copy);
    if (arg >= 0) {
      if (options.flag[1] == '+')
        dest[0] = '+';
      else
        dest[0] = ' ';

      for (int i = 0; (s21_size_t int)i < s21_strlen(dest_copy); i++) {
        dest[i + 1] = dest_copy[i];
      }
    }

    // printf("dest with +:%s\n", dest);

    free(dest_copy);
  } else if (arg < 0) {
    dest[s21_strlen(dest)] = '\0';
    for (int i = s21_strlen(dest); i > 0; i--) {
      dest[i] = dest[i - 1];
    }
    dest[0] = '-';
  }

  // width

  if (s21_strlen(dest) < (s21_size_t int)options.width) {
    char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
    s21_memcpy(dest_copy, dest, s21_strlen(dest));
    // printf("dest_copy:%s()\n", dest_copy);
    int count_of_space = options.width - s21_strlen(dest);
    int i = 0;
    int step = 0;
    if (options.flag[0] == '-') step = s21_strlen(dest);

    for (; i < count_of_space; i++) {
      if (options.flag[4] == '0')
        dest[i + step] = '0';
      else
        dest[i + step] = ' ';
    }
    // printf("now dest:%s()\n", dest);

    // s21_insert(dest, dest_copy, i)    start    here
    if (options.flag[0] != '-') {
      int n = 0;
      for (; i < options.width; i++) {
        dest[i] = dest_copy[n];
        n++;
      }
    }
    // s21_insert(dest, dest_copy, i)     finish    here
    free(dest_copy);
  }

  // printf("final dest:%s()\n", dest);

  for (int i = 0; (s21_size_t int)i < s21_strlen(dest); i++) {
    *output_string_pointer = dest[i];
    output_string_pointer++;

    //*p_output_string_pointer++;
    // printf("output_string_pointer = %d\n", output_string_pointer);
  }

  if (flag_free == 1) {
    free(dest);
  }
  free(dest_1);

  return output_string_pointer;
}

char *s21_type_s_for_char(char *arg, struct variables options,
                          char *output_string_pointer) {
  char *dest = calloc(MAX_STRING_LEN, sizeof(char));

  for (int i = 0; (s21_size_t int)i < s21_strlen(arg); i++) {
    dest[i] = arg[i];
  }

  if (options.precision >= 0 && (int)s21_strlen(dest) > options.precision) {
    int len = s21_strlen(dest);
    for (int i = options.precision; i < len; i++) dest[i] = '\0';
  }

  if (s21_strlen(dest) < (s21_size_t int)options.width) {
    char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
    s21_memcpy(dest_copy, dest, s21_strlen(dest));
    // printf("dest_copy:%s()\n", dest_copy);
    int count_of_space = options.width - s21_strlen(dest);
    int i = 0;
    int step = 0;
    if (options.flag[0] == '-') step = s21_strlen(dest);

    for (; i < count_of_space; i++) {
      if (options.flag[4] == '0')
        dest[i + step] = '0';
      else
        dest[i + step] = ' ';
    }
    // printf("now dest:%s()\n", dest);

    // s21_insert(dest, dest_copy, i)    start    here
    if (options.flag[0] != '-') {
      int n = 0;
      for (; i < options.width; i++) {
        dest[i] = dest_copy[n];
        n++;
      }
    }
    // s21_insert(dest, dest_copy, i)     finish    here
    free(dest_copy);
  }

  // printf("now dest:%s()\n", dest);
  ///////////////////
  ///////////////////

  // printf("final dest:%s()\n", dest);

  for (int i = 0; (s21_size_t int)i < s21_strlen(dest); i++) {
    *output_string_pointer = dest[i];
    output_string_pointer++;

    //*p_output_string_pointer++;
    // printf("output_string_pointer = %d\n", output_string_pointer);
  }

  free(dest);

  return output_string_pointer;
}

char *s21_type_c_for_int(char arg, struct variables options,
                         char *output_string_pointer) {
  char *dest = calloc(MAX_STRING_LEN, sizeof(char));
  dest[0] = arg;

  if (s21_strlen(dest) < (s21_size_t int)options.width) {
    char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
    s21_memcpy(dest_copy, dest, s21_strlen(dest));
    // printf("dest_copy:%s()\n", dest_copy);
    int count_of_space = options.width - s21_strlen(dest);
    int i = 0;
    int step = 0;
    if (options.flag[0] == '-') step = s21_strlen(dest);

    for (; i < count_of_space; i++) {
      if (options.flag[4] == '0')
        dest[i + step] = '0';
      else
        dest[i + step] = ' ';
    }
    // printf("now dest:%s()\n", dest);

    // s21_insert(dest, dest_copy, i)    start    here
    if (options.flag[0] != '-') {
      int n = 0;
      for (; i < options.width; i++) {
        dest[i] = dest_copy[n];
        n++;
      }
    }
    // s21_insert(dest, dest_copy, i)     finish    here
    free(dest_copy);
  }

  // printf("final dest:%s()\n", dest);

  for (int i = 0; (s21_size_t int)i < s21_strlen(dest); i++) {
    *output_string_pointer = dest[i];
    output_string_pointer++;

    //*p_output_string_pointer++;
    // printf("output_string_pointer = %d\n", output_string_pointer);
  }

  free(dest);

  return output_string_pointer;
}

char *s21_type_p_for_void(void *arg, struct variables options,
                          char *output_string_pointer) {
  uintptr_t address = (uintptr_t)arg;

  char *dest = calloc(MAX_STRING_LEN, sizeof(char));

  dest = s21_long_to_string(dest, address, 16, LOW_CASE);

  //            precision
  if (options.precision == 0 && arg == 0) {
    dest[0] = '\0';
  } else if ((int)s21_strlen(dest) < options.precision) {
    char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
    s21_memcpy(dest_copy, dest, s21_strlen(dest));
    // printf("dest_copy:%s()\n", dest_copy);
    int count_of_zero = options.precision - s21_strlen(dest);
    int i = 0;

    for (; i < count_of_zero; i++) {
      dest[i] = '0';
    }

    // s21_insert(dest, dest_copy, i)    start    here
    int n = 0;
    for (; i < options.precision; i++) {
      dest[i] = dest_copy[n];
      n++;
    }
    // s21_insert(dest, dest_copy, i)     finish    here
    free(dest_copy);
  }
  // printf("dest:%s()\n", dest);

  // for flag # and type x/X

  char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
  s21_memcpy(dest_copy, dest, s21_strlen(dest));
  dest[0] = '0';
  dest[1] = 'x';

  for (int i = 0; (s21_size_t int)i < s21_strlen(dest_copy); i++) {
    dest[i + 2] = dest_copy[i];
  }
  free(dest_copy);

  // width

  if (s21_strlen(dest) < (s21_size_t int)options.width) {
    char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
    s21_memcpy(dest_copy, dest, s21_strlen(dest));
    // printf("dest_copy:%s()\n", dest_copy);
    int count_of_space = options.width - s21_strlen(dest);
    int i = 0;
    int step = 0;
    if (options.flag[0] == '-') step = s21_strlen(dest);

    for (; i < count_of_space; i++) {
      if (options.flag[4] == '0')
        dest[i + step] = '0';
      else
        dest[i + step] = ' ';
    }
    // printf("now dest:%s()\n", dest);

    // s21_insert(dest, dest_copy, i)    start    here
    if (options.flag[0] != '-') {
      int n = 0;
      for (; i < options.width; i++) {
        dest[i] = dest_copy[n];
        n++;
      }
    }
    // s21_insert(dest, dest_copy, i)     finish    here
    free(dest_copy);
  }

  // printf("final dest:%s()\n", dest);

  for (int i = 0; (s21_size_t int)i < s21_strlen(dest); i++) {
    *output_string_pointer = dest[i];
    output_string_pointer++;

    //*p_output_string_pointer++;
    // printf("output_string_pointer = %d\n", output_string_pointer);
  }

  free(dest);

  return output_string_pointer;
}

void s21_doubleToString(double number, char *rezult, int accuracy,
                        int is_sharp) {
  int modifire = 0, is_negative = 0;

  ////////////
  // if (number > 0)printf("OOOOOO number = %.30Lf\n", (long double)number);
  /////////////
  if (number < 0) {
    number *= -1.0;  // get positiv number
    is_negative = 1;
  }

  int intPart = (int)number;
  double decimalPart = fabs(number - intPart);

  // printf("intPart = %d\n", intPart);
  // printf("LLLLL %lf  %lf\n", (double)(int)number, number);
  if (accuracy == 0) {
    // int int_number = (int)number;
    // double first_dec = (number - int_number) * 10;
    // int int_first_dec = (int)first_dec;
    // if (int_number % 2 == 1 && int_first_dec == 5) int_number++;
    // number = (double)int_number;
    number = round(number);
    // printf("number = %f\n", number);
    int int_number = (int)number;
    int intDigits = (int)log10(fabs((float)int_number)) + 1;
    // printf("HHHH int_number = %d  intDigit = %d\n", int_number, intDigits);
    int i = intDigits - 1;
    while (int_number > 0) {
      rezult[i] = (int_number % 10) + '0';
      int_number /= 10;
      i--;
    }

    if (number == 0) {
      rezult[0] = '0';
      rezult[1] = '\0';
    }

    if (is_sharp == 1) {
      rezult[s21_strlen(rezult)] = '.';
      rezult[s21_strlen(rezult)] = '\0';
    }

  }

  else if (number == (double)(int)number) {
    // printf("fff number = %f\n", number);
    int int_number = (int)number;
    int intDigits = (int)log10(fabs((float)intPart)) + 1;

    // printf("HHHH int_number = %d  intDigit = %d\n", int_number, intDigits);

    int i = intDigits - 1;
    // printf("i = %d\n", i);
    while (int_number > 0) {
      rezult[i] = (int_number % 10) + '0';
      int_number /= 10;
      // printf("here int_number = %d  rezult i : %c\n", int_number, rezult[i]);
      i--;
    }

    if (number == 0) {
      rezult[0] = '0';
      intDigits = 1;
    }

    rezult[intDigits] = '\0';

    // printf("HHHH 1 rez: %s\n", rezult);
    //  printf("HHHH number = %f\n", number);

    int len = s21_strlen(rezult);
    rezult[len] = '.';

    // printf("HHHH 2 rez: %s\n", rezult);

    for (int i = 0; i < accuracy; i++) {
      rezult[len + 1 + i] = '0';
    }

  }

  else {
    char *str = calloc(1024, sizeof(char));

    // printf("intPart = %d\n", intPart);
    // printf("double decimalPart = %lf\n", decimalPart);

    // Calculate the number of digits in the integer part
    int intDigits = (int)log10(fabs((float)intPart)) + 1;
    // Calculate the number of decimal places required
    int decimalPlaces =
        (decimalPart != 0.0) ? (int)log10(1.0 / decimalPart) + 1 : 0;

    // printf("intDigits = %d\ndecimalPlaces = %d\n", intDigits, decimalPlaces);

    // int size = intDigits + decimalPlaces + 2;  // +2 for decimal point and
    // null terminator

    // printf("size = %d\n", size);

    // Convert the integer part to string
    int i = intDigits - 1;

    if (intPart == 0) {
      str[0] = '0';
      intDigits = 1;
    } else {
      while (intPart > 0) {
        str[i] = (intPart % 10) + '0';
        intPart /= 10;
        i--;
      }
    }

    // printf("0 str: %s\n", str);

    // printf("1 str: %s\n", str);

    // Add the decimal point if necessary
    // printf("decimalPlaces = %d\n", decimalPlaces);
    int index_after_point = i;

    if (decimalPlaces > 0) {
      str[intDigits] = '.';
      i = intDigits + 1 /*+ decimalPlaces*/;

      // printf("2 str: %s\n", str);
      // printf("i = %d\n", i);

      index_after_point = i;

      // Convert the decimal part to string

      while (decimalPart > 0) {
        decimalPart *= 10;
        int digit = (int)decimalPart;
        // printf("digit = %d\n", digit);
        str[i] = digit + '0';
        decimalPart -= digit;
        decimalPlaces--;
        i++;
      }
    }

    // printf("3 str: %s\n", str);

    // if 5 modifire in 49999999...
    // for (int f = intDigits + 1; (s21_size_t int)f < s21_strlen(str); f++) {
    //   if (str[f] == '9') {
    //     int count_nine = 0;
    //     for (int s = f + 1; (s21_size_t int)s < s21_strlen(str); s++) {
    //       if (str[s] == '9')
    //         count_nine++;
    //       else
    //         break;
    //     }
    //     if (count_nine > 5) {
    //       if (str[f - 1] == '.') {
    //         if (str[f - 2] == '9') {
    //           modifire = 1;
    //         } else {
    //           str[f - 2] = str[f - 2] + 1;
    //         }
    //       } else {
    //         str[f - 1] = str[f - 1] + 1;
    //       }
    //       str[f + 1] = '\0';
    //       str[f] = '\0';
    //     }
    //   }
    // }

    for (int j = 0; j < index_after_point; j++) {
      rezult[j] = str[j];
    }
    // printf("4 rezult: %s\n", rezult);
    int last_digit_index = index_after_point + accuracy - 1;
    if (index_after_point >= 0) {
      for (int j = index_after_point; j < last_digit_index; j++) {
        rezult[j] = str[j];
      }
    }
    ///////////////
    ///////////////
    else {
      s21_doubleToString(0, rezult, accuracy, is_sharp);
      index_after_point = 0;
      last_digit_index = 0;
    }
    ///////////////
    //////////////

    char next_simbol = str[last_digit_index + 1];
    // printf("next simbol = %c\n", next_simbol);
    // printf("5 rezult: %s\n", rezult);
    if (next_simbol <= '4') {
      rezult[last_digit_index] = str[last_digit_index];
    } else if (next_simbol >= '6') {
      int copy = last_digit_index;
      if (str[copy] == '9') {
        while (str[copy] == '9') {
          // while ( last_digit_index - back_to_norm_digit == '9' ) {
          rezult[copy] = '0';
          // back_to_norm_digit ++;
          // }
          copy--;
        }
        if (str[copy] == '.') {
          rezult[copy] = '.';
          copy--;
        }
        if (str[copy] == '9') {
          modifire = 1;
        } else {
          rezult[copy] = str[copy] + 1;
        }
      } else {
        rezult[last_digit_index] = str[last_digit_index] + 1;
      }
    } else if (next_simbol == '5') {
      int flag_trash = 0;

      for (int m = last_digit_index + 2; (s21_size_t int)m < s21_strlen(str);
           m++) {
        if (str[m] != '0') {
          flag_trash = 1;
          break;
        }
      }

      if (flag_trash == 1) {
        int copy = last_digit_index;
        if (str[copy] == '9') {
          while (str[copy] == '9') {
            // while ( last_digit_index - back_to_norm_digit == '9' ) {
            rezult[copy] = '0';
            copy--;
          }
          if (str[copy] == '.') {
            rezult[copy] = '.';
            copy--;
            if (rezult[copy] == '9') {
              modifire = 1;
            } else {
              rezult[copy] = rezult[copy] + 1;
            }
          } else {
            rezult[copy] = rezult[copy] + 1;
          }
        } else {
          rezult[last_digit_index] = str[last_digit_index] + 1;
        }
      } else {
        rezult[last_digit_index] = str[last_digit_index];
      }
    }

    // printf("4 rezult: %s\n", rezult);
    // printf("len rezult = %d\n", strlen(rezult));

    if (s21_strlen(rezult) - intDigits - 1 < (s21_size_t int)accuracy) {
      for (int m = s21_strlen(rezult); m < accuracy + intDigits + 1; m++) {
        // printf("m = %d\n", m);
        rezult[m] = '0';
      }
    }

    if (modifire == 1) {
      for (int y = 0; (s21_size_t int)y < s21_strlen(rezult); y++) {
        rezult[y] = '\0';
      }
      // printf("PODACHA = %f\n", (double)((int)number+1));
      s21_doubleToString((double)((int)number + 1), rezult, accuracy, is_sharp);
    }

    int point_is_here = 0;
    for (int y = 0; (s21_size_t int)y < s21_strlen(rezult); y++) {
      if (rezult[y] == '.' && point_is_here == 1) {
        rezult[y] = '\0';
        rezult[y + 1] = '\0';
        break;
      }
      if (rezult[y] == '.') {
        point_is_here = 1;
      }
    }

    free(str);
  }

  if (is_negative == 1) {
    rezult[s21_strlen(rezult) + 1] = '\0';
    for (int i = s21_strlen(rezult); i > 0; i--) {
      rezult[i] = rezult[i - 1];
    }
    rezult[0] = '-';
  }
}

void s21_long_doubleToString(long double number, char *rezult, int accuracy,
                             int is_sharp) {
  int modifire = 0, is_negative = 0;

  // printf("JJJJJJ %Lf", number);

  if (number < 0) {
    number *= -1.0;  // get positiv number
    is_negative = 1;
  }

  long int intPart = (long int)number;
  long double decimalPart = (long double)fabs((double)number - (double)intPart);

  // printf("intPart = %ld\n", intPart);
  // printf("decimalPart = %Lf\n", decimalPart);

  if (accuracy == 0) {
    // int int_number = (int)number;
    // double first_dec = (number - int_number) * 10;
    // int int_first_dec = (int)first_dec;
    // if (int_number % 2 == 1 && int_first_dec == 5) int_number++;
    // number = (double)int_number;
    number = round(number);
    // printf("number = %f\n", number);
    int int_number = (int)number;
    int intDigits = (int)log10(fabs((float)int_number)) + 1;
    // printf("HHHH int_number = %d  intDigit = %d\n", int_number, intDigits);
    int i = intDigits - 1;
    while (int_number > 0) {
      rezult[i] = (int_number % 10) + '0';
      int_number /= 10;
      i--;
    }

    if (number == 0) {
      rezult[0] = '0';
      rezult[1] = '\0';
    }

    if (is_sharp == 1) {
      rezult[s21_strlen(rezult)] = '.';
      rezult[s21_strlen(rezult)] = '\0';
    }

  }

  else if (number == (long double)(int)number) {
    int int_number = (int)number;
    int intDigits = (int)log10(fabs((float)intPart)) + 1;

    // printf("HHHH int_number = %d  intDigit = %d\n", int_number, intDigits);

    int i = intDigits - 1;
    // printf("i = %d\n", i);
    while (int_number > 0) {
      rezult[i] = (int_number % 10) + '0';
      int_number /= 10;
      // printf("here int_number = %d  rezult i : %c\n", int_number, rezult[i]);
      i--;
    }

    if (number == 0) {
      rezult[0] = '0';
      intDigits = 1;
    }

    rezult[intDigits] = '\0';

    // printf("HHHH 1 rez: %s\n", rezult);
    //  printf("HHHH number = %f\n", number);

    int len = s21_strlen(rezult);
    rezult[len] = '.';

    // printf("HHHH 2 rez: %s\n", rezult);

    for (int i = 0; i < accuracy; i++) {
      rezult[len + 1 + i] = '0';
    }

  }

  else {
    char *str = calloc(1024, sizeof(char));

    // printf("intPart = %d\n", intPart);
    // printf("double decimalPart = %lf\n", decimalPart);

    // Calculate the number of digits in the integer part
    int intDigits = (int)log10(fabs((float)intPart)) + 1;
    // Calculate the number of decimal places required
    int decimalPlaces =
        (decimalPart != 0.0) ? (int)log10(1.0 / decimalPart) + 1 : 0;

    // printf("intDigits = %d\ndecimalPlaces = %d\n", intDigits, decimalPlaces);

    // int size = intDigits + decimalPlaces + 2;  // +2 for decimal point and
    // null terminator

    // printf("size = %d\n", size);

    // Convert the integer part to string
    int i = intDigits - 1;

    if (intPart == 0) {
      str[0] = '0';
      intDigits = 1;
    } else {
      while (intPart > 0) {
        str[i] = (intPart % 10) + '0';
        intPart /= 10;
        i--;
      }
    }

    // printf("0 str: %s\n", str);

    // printf("1 str: %s\n", str);

    // Add the decimal point if necessary

    int index_after_point = i;

    if (decimalPlaces > 0) {
      str[intDigits] = '.';
      i = intDigits + 1 /*+ decimalPlaces*/;

      // printf("2 str: %s\n", str);
      // printf("i = %d\n", i);

      index_after_point = i;

      // Convert the decimal part to string

      while (decimalPart > 0) {
        decimalPart *= 10;
        int digit = (int)decimalPart;
        // printf("digit = %d\n", digit);
        str[i] = digit + '0';
        decimalPart -= digit;
        decimalPlaces--;
        i++;
      }
    }

    // printf("3 str: %s\n", str);

    // if 5 modifire in 49999999...
    // for (int f = intDigits + 1; (s21_size_t int)f < s21_strlen(str); f++) {
    //   if (str[f] == '9') {
    //     int count_nine = 0;
    //     for (int s = f + 1; (s21_size_t int)s < s21_strlen(str); s++) {
    //       if (str[s] == '9')
    //         count_nine++;
    //       else
    //         break;
    //     }
    //     if (count_nine > 5) {
    //       if (str[f - 1] == '.') {
    //         if (str[f - 2] == '9') {
    //           modifire = 1;
    //         } else {
    //           str[f - 2] = str[f - 2] + 1;
    //         }
    //       } else {
    //         str[f - 1] = str[f - 1] + 1;
    //       }
    //       str[f + 1] = '\0';
    //       str[f] = '\0';
    //     }
    //   }
    // }

    for (int j = 0; j < index_after_point; j++) {
      rezult[j] = str[j];
    }

    int last_digit_index = index_after_point + accuracy - 1;
    for (int j = index_after_point; j < last_digit_index; j++) {
      rezult[j] = str[j];
    }

    char next_simbol = str[last_digit_index + 1];
    // printf("next simbol = %c\n", next_simbol);

    if (next_simbol <= '4') {
      rezult[last_digit_index] = str[last_digit_index];
    } else if (next_simbol >= '6') {
      int copy = last_digit_index;
      if (str[copy] == '9') {
        while (str[copy] == '9') {
          // while ( last_digit_index - back_to_norm_digit == '9' ) {
          rezult[copy] = '0';
          // back_to_norm_digit ++;
          // }
          copy--;
        }
        if (str[copy] == '.') {
          rezult[copy] = '.';
          copy--;
        }
        if (str[copy] == '9') {
          modifire = 1;
        } else {
          rezult[copy] = str[copy] + 1;
        }
      } else {
        rezult[last_digit_index] = str[last_digit_index] + 1;
      }
    } else if (next_simbol == '5') {
      int flag_trash = 0;

      for (int m = last_digit_index + 2; (s21_size_t int)m < s21_strlen(str);
           m++) {
        if (str[m] != '0') {
          flag_trash = 1;
          break;
        }
      }

      if (flag_trash == 1) {
        int copy = last_digit_index;
        if (str[copy] == '9') {
          while (str[copy] == '9') {
            // while ( last_digit_index - back_to_norm_digit == '9' ) {
            rezult[copy] = '0';
            copy--;
          }
          if (str[copy] == '.') {
            rezult[copy] = '.';
            copy--;
            if (rezult[copy] == '9') {
              modifire = 1;
            } else {
              rezult[copy] = rezult[copy] + 1;
            }
          } else {
            rezult[copy] = rezult[copy] + 1;
          }
        } else {
          rezult[last_digit_index] = str[last_digit_index] + 1;
        }
      } else {
        rezult[last_digit_index] = str[last_digit_index];
      }
    }

    // printf("4 rezult: %s\n", rezult);
    // printf("len rezult = %d\n", strlen(rezult));

    if (s21_strlen(rezult) - intDigits - 1 < (s21_size_t int)accuracy) {
      for (int m = s21_strlen(rezult); m < accuracy + intDigits + 1; m++) {
        // printf("m = %d\n", m);
        rezult[m] = '0';
      }
    }

    if (modifire == 1) {
      for (int y = 0; (s21_size_t int)y < s21_strlen(rezult); y++) {
        rezult[y] = '\0';
      }
      // printf("PODACHA = %f\n", (double)((int)number+1));
      s21_long_doubleToString((long double)((int)number + 1), rezult, accuracy,
                              is_sharp);
    }

    int point_is_here = 0;
    for (int y = 0; (s21_size_t int)y < s21_strlen(rezult); y++) {
      if (rezult[y] == '.' && point_is_here == 1) {
        rezult[y] = '\0';
        rezult[y + 1] = '\0';
        break;
      }
      if (rezult[y] == '.') {
        point_is_here = 1;
      }
    }

    free(str);
  }

  if (is_negative == 1) {
    rezult[s21_strlen(rezult) + 1] = '\0';
    for (int i = s21_strlen(rezult); i > 0; i--) {
      rezult[i] = rezult[i - 1];
    }
    rezult[0] = '-';
  }
}
