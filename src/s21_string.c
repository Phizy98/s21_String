#include "s21_string.h"

// #ifdef __APPLE__
// // os = 1;
// // const int len_mac = 106;

// const char *array_errors_mac[107] = {
//     NULL,
//     "Operation not permitted",
//     "No such file or directory",
//     "No such process",
//     "Interrupted system call",
//     "Input/output error",
//     "Device not configured",
//     "Argument list too long",
//     "Exec format error",
//     "Bad file descriptor",
//     "No child processes",
//     "Resource deadlock avoided",
//     "Cannot allocate memory",
//     "Permission denied",
//     "Bad address",
//     "Block device required",
//     "Resource busy",
//     "File exists",
//     "Cross-device link",
//     "Operation not supported by device",
//     "Not a directory",
//     "Is a directory",
//     "Invalid argument",
//     "Too many open files in system",
//     "Too many open files",
//     "Inappropriate ioctl for device",
//     "Text file busy",
//     "File too large",
//     "No space left on device",
//     "Illegal seek",
//     "Read-only file system",
//     "Too many links",
//     "Broken pipe",
//     "Numerical argument out of domain",
//     "Result too large",
//     "Resource temporarily unavailable",
//     "Operation now in progress",
//     "Operation already in progress",
//     "Socket operation on non-socket",
//     "Destination address required",
//     "Message too long",
//     "Protocol wrong type for socket",
//     "Protocol not available",
//     "Protocol not supported",
//     "Socket type not supported",
//     "Operation not supported",
//     "Protocol family not supported",
//     "Address family not supported by protocol family",
//     "Address already in use",
//     "Can't assign requested address",
//     "Network is down",
//     "Network is unreachable",
//     "Network dropped connection on reset",
//     "Software caused connection abort",
//     "Connection reset by peer",
//     "No buffer space available",
//     "Socket is already connected",
//     "Socket is not connected",
//     "Can't send after socket shutdown",
//     "Too many references: can't splice",
//     "Operation timed out",
//     "Connection refused",
//     "Too many levels of symbolic links",
//     "File name too long",
//     "Host is down",
//     "No route to host",
//     "Directory not empty",
//     "Too many processes",
//     "Too many users",
//     "Disc quota exceeded",
//     "Stale NFS file handle",
//     "Too many levels of remote in path",
//     "RPC struct is bad",
//     "RPC version wrong",
//     "RPC prog. not avail",
//     "Program version wrong",
//     "Bad procedure for program",
//     "No locks available",
//     "Function not implemented",
//     "Inappropriate file type or format",
//     "Authentication error",
//     "Need authenticator",
//     "Device power is off",
//     "Device error",
//     "Value too large to be stored in data type",
//     "Bad executable (or shared library)",
//     "Bad CPU type in executable",
//     "Shared library version mismatch",
//     "Malformed Mach-o file",
//     "Operation canceled",
//     "Identifier removed",
//     "No message of desired type",
//     "Illegal byte sequence",
//     "Attribute not found",
//     "Bad message",
//     "EMULTIHOP (Reserved)",
//     "No message available on STREAM",
//     "ENOLINK (Reserved)",
//     "No STREAM resources",
//     "Not a STREAM",
//     "Protocol error",
//     "STREAM ioctl timeout",
//     "Operation not supported on socket",
//     "Policy not found",
//     "State not recoverable",
//     "Previous owner died",
//     "Interface output queue is full"};
// // array_errors = array_errors_mac;

// #elif __linux__

// // const int len_linux = 133;

// const char *array_errors_linux[134] = {
//     "Success",
//     "Operation not permitted",
//     "No such file or directory",
//     "No such process",
//     "Interrupted system call",
//     "Input/output error",
//     "No such device or address",
//     "Argument list too long",
//     "Exec format error",
//     "Bad file descriptor",
//     "No child processes",
//     "Resource temporarily unavailable",
//     "Cannot allocate memory",
//     "Permission denied",
//     "Bad address",
//     "Block device required",
//     "Device or resource busy",
//     "File exists",
//     "Invalid cross-device link",
//     "No such device",
//     "Not a directory",
//     "Is a directory",
//     "Invalid argument",
//     "Too many open files in system",
//     "Too many open files",
//     "Inappropriate ioctl for device",
//     "Text file busy",
//     "File too large",
//     "No space left on device",
//     "Illegal seek",
//     "Read-only file system",
//     "Too many links",
//     "Broken pipe",
//     "Numerical argument out of domain",
//     "Numerical result out of range",
//     "Resource deadlock avoided",
//     "File name too long",
//     "No locks available",
//     "Function not implemented",
//     "Directory not empty",
//     "Too many levels of symbolic links",
//     "Unknown error 41",
//     "No message of desired type",
//     "Identifier removed",
//     "Channel number out of range",
//     "Level 2 not synchronized",
//     "Level 3 halted",
//     "Level 3 reset",
//     "Link number out of range",
//     "Protocol driver not attached",
//     "No CSI structure available",
//     "Level 2 halted",
//     "Invalid exchange",
//     "Invalid request descriptor",
//     "Exchange full",
//     "No anode",
//     "Invalid request code",
//     "Invalid slot",
//     "Unknown error 58",
//     "Bad font file format",
//     "Device not a stream",
//     "No data available",
//     "Timer expired",
//     "Out of streams resources",
//     "Machine is not on the network",
//     "Package not installed",
//     "Object is remote",
//     "Link has been severed",
//     "Advertise error",
//     "Srmount error",
//     "Communication error on send",
//     "Protocol error",
//     "Multihop attempted",
//     "RFS specific error",
//     "Bad message",
//     "Value too large for defined data type",
//     "Name not unique on network",
//     "File descriptor in bad state",
//     "Remote address changed",
//     "Can not access a needed shared library",
//     "Accessing a corrupted shared library",
//     ".lib section in a.out corrupted",
//     "Attempting to link in too many shared libraries",
//     "Cannot exec a shared library directly",
//     "Invalid or incomplete multibyte or wide character",
//     "Interrupted system call should be restarted",
//     "Streams pipe error",
//     "Too many users",
//     "Socket operation on non-socket",
//     "Destination address required",
//     "Message too long",
//     "Protocol wrong type for socket",
//     "Protocol not available",
//     "Protocol not supported",
//     "Socket type not supported",
//     "Operation not supported",
//     "Protocol family not supported",
//     "Address family not supported by protocol",
//     "Address already in use",
//     "Cannot assign requested address",
//     "Network is down",
//     "Network is unreachable",
//     "Network dropped connection on reset",
//     "Software caused connection abort",
//     "Connection reset by peer",
//     "No buffer space available",
//     "Transport endpoint is already connected",
//     "Transport endpoint is not connected",
//     "Cannot send after transport endpoint shutdown",
//     "Too many references: cannot splice",
//     "Connection timed out",
//     "Connection refused",
//     "Host is down",
//     "No route to host",
//     "Operation already in progress",
//     "Operation now in progress",
//     "Stale file handle",
//     "Structure needs cleaning",
//     "Not a XENIX named type file",
//     "No XENIX semaphores available",
//     "Is a named type file",
//     "Remote I/O error",
//     "Disk quota exceeded",
//     "No medium found",
//     "Wrong medium type",
//     "Operation canceled",
//     "Required key not available",
//     "Key has expired",
//     "Key has been revoked",
//     "Key was rejected by service",
//     "Owner died",
//     "State not recoverable",
//     "Operation not possible due to RF-kill",
//     "Memory page has hardware error"  // 133
// };
// // array_errors = array_errors_linux;
// #endif

void *s21_memchr(const void *p, int c, s21_size_t n) {
  void *res = s21_NULL;
  for (s21_size_t i = 0; i < n; i++)
    if (*((char *)p + i) == c) {
      res = (void *)(p + i);
      break;
    }

  return res;
}
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int res = 0;
  for (s21_size_t i = 0; i < n; i++) {
    res = *((char *)str1 + i) - *((char *)str2 + i);
    if (res != 0) break;
  }
  return res;
}
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i++) *((char *)dest + i) = *((char *)src + i);

  return dest;
}
void *s21_memset(void *p, int c, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i++) {
    *((char *)p + i) = c;
  }

  return p;
}
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *p = dest;
  while (*p) p++;
  for (s21_size_t i = 0; i < n; i++) {
    *(p + i) = *(src + i);
    if (!*(src + i)) break;
  }

  return dest;
}
char *s21_strchr(const char *p, int c) {
  char *res = s21_NULL;
  s21_size_t len = s21_strlen(p);
  for (s21_size_t i = 0; i <= len; i++) {
    if (*p == c) {
      res = (char *)p;
      break;
    }
    p++;
  }

  return res;
}
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res = 0;
  for (s21_size_t i = 0; i < n; i++) {
    res = *(str1 + i) - *(str2 + i);
    if (res || !*(str1 + i) || !*(str2 + i)) break;
  }

  return res;
}
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i++) {
    *(dest + i) = *(src + i);
    if (*(src + i) == '\0') break;
  }

  return dest;
}
s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t len = 0;
  int flag = 0;
  while (*str1 != '\0') {
    for (s21_size_t i = 0; *(str2 + i) != '\0'; i++)
      if (*str1 == *(str2 + i)) {
        flag++;
        break;
      }
    if (flag) break;
    len++;
    str1++;
  }

  return len;
}
// // char *s21_strerror(int errnum){
// //     if(errnum > 0 && errnum < 107) return (char *)errors[errnum];
// //     return s21_NULL;
// // }

char *s21_strerror(int errnum) {
  if (errnum > 0) {
    ;
  }
  //   // int len = 0;
  //   //  if (os == 0) len = 133;
  //   //  else if (os == 1) len = 106;
  //   int flag_error = 0;
  //   char str[MAX_STRING_LEN] = {"\0"};
  // #ifdef __APPLE__
  //   if (errnum > 106 || errnum < 0) {
  //     s21_sprintf(str, "Unknown error: %d", errnum);
  //   } else if (errnum == 0) {
  //     s21_sprintf(str, "Undefined error: %d", errnum);
  //   } else {
  //     for (int i = 0; (s21_size_t)i < s21_strlen(array_errors_mac[errnum]);
  //     i++) {
  //       str[i] = array_errors_mac[errnum][i];
  //     }
  //   }
  // #elif __linux__
  //   if (errnum > 133 || errnum < 0) {
  //     s21_sprintf(str, "Unknown error %d", errnum);
  //   } else {
  //     for (int i = 0; (s21_size_t)i < s21_strlen(array_errors_linux[errnum]);
  //          i++) {
  //       str[i] = array_errors_linux[errnum][i];
  //     }
  //   }

  // #endif
  return s21_NULL;
}

s21_size_t s21_strlen(const char *p) {
  s21_size_t len = 0;
  if (p != s21_NULL) {
    while (*(p + len)) len++;
  }

  return len;
}

// char *s21_strpbrk(const char *str1, const char *str2) {
//     return s21_NULL;
// }
// char *s21_strrchr(const char *p, int c) {
//     return s21_NULL;
// }
// char *s21_strstr(const char *haystack, const char *needle) {
//     return s21_NULL;
// }
// char *s21_strtok(char *p, const char *delim) {
//     return s21_NULL;
// }

// char *s21_strpbrk(const char *str1, const char *str2) {
//   const char *p1;
//   const char *p2;
//   char *result = s21_NULL;

//   for (p1 = str1; *p1 != '\0'; ++p1) {
//     for (p2 = str2; *p2 != '\0'; ++p2) {
//       if (*p1 == *p2) {
//         result = (char *)p1;
//         break;
//       }
//     }
//     if (result != s21_NULL) {
//       break;
//     }
//   }
//   return result;
// }
char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = s21_NULL;

  /*Выполняет поиск во внутреннем массиве номера ошибки errnum и возвращает
   * указатель на строку с сообщением об ошибке. Нужно объявить макросы,
   * содержащие массивы сообщений об ошибке для операционных систем mac и linux.
   * Описания ошибок есть в оригинальной библиотеке. Проверка текущей ОС
   * осуществляется с помощью директив*/
  for (; *str1 != '\0'; ++str1) {
    if (s21_strchr(str2, *str1) != s21_NULL) {
      result = (char *)str1;
      break;
    }
  }
  return result;
}

char *s21_strrchr(const char *str, int c) {
  const char *last_occurence = s21_NULL;

  while (*str != '\0') {
    if (*str == c) {
      last_occurence = str;
    }
    ++str;
  }
  return (char *)last_occurence;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = s21_NULL;

  if (*needle == '\0') {
    result = (char *)haystack;
  } else {
    while (*haystack != '\0') {
      const char *h = haystack;
      const char *n = needle;

      while (*n != '\0' && *h == *n) {
        ++h;
        ++n;
      }

      if (*n == '\0') {
        result = (char *)haystack;
        break;
      }

      ++haystack;
    }
  }

  return result;
}

// char *s21_strtok(char *str, const char *delim) { //изначально было strtok,
// заменил на s21_strtok
//   static char *next_token = s21_NULL;
//   char *token_start = s21_NULL;

//   if (str != s21_NULL) {
//     next_token = str;
//   }

//   while (*next_token != '\0' && s21_strchr(delim, *next_token) != s21_NULL) {
//     ++next_token;
//   }

//   token_start = next_token;

//   while (*next_token != '\0' && s21_strchr(delim, *next_token) != s21_NULL) {
//     ++next_token;
//   }

//   if (*next_token == '\0') {
//     next_token = s21_NULL;
//   } else {
//     *next_token++ = '\0';
//   }

//   return token_start;
// }

char *s21_strtok(char *str, const char *delim) {
  static char *next_token = s21_NULL;
  char *token_start = s21_NULL;

  if (str != s21_NULL) {
    next_token = str;
  }  //////////////////
  //добавлено
  else {
    if (next_token == s21_NULL) {
      return s21_NULL;
    }
  }
  //добавлено
  ////////////////////////

  while (*next_token != '\0' && s21_strchr(delim, *next_token) != s21_NULL) {
    ++next_token;
  }

  ///////////////////////
  //добавлено
  if (*next_token == '\0') {
    next_token = s21_NULL;
    return s21_NULL;
  }
  //добавлено
  ///////////////////////

  token_start = next_token;

  while (*next_token != '\0' && s21_strchr(delim, *next_token) != s21_NULL) {
    ++next_token;
  }

  if (*next_token == '\0') {
    next_token = s21_NULL;
  } else {
    *next_token++ = '\0';
  }

  return token_start;
}

// char *s21_short_to_string(char* dest, unsigned short number, int base, int
// hight) {
//     int is_negative = 0;    //flag negative number
//     char *string_pointer = dest;

//     if(base == 0) base = 10;
//     else if(base == 10 && (short)number < 0) {
//         number = ~number + 1;    //reverse bytes for negative number
//         is_negative = 1;    //set negative flag
//     }

//     do {
//         *string_pointer++ = s21_number_to_char(number % base, hight); //get
//         remainder of div and add to result string number /= base;
//     } while (number != 0);  //fill string with number

//     if(base == 10 && is_negative) *string_pointer++ = '-'; //set '-' for
//     negative decimal number *string_pointer = '\0'; //set end of string
//     s21_reverse_string(dest);

//     return dest;
// }
char *s21_int_to_string(char *dest, unsigned int number, int base, int hight) {
  int is_negative = 0;  // flag negative number
  char *string_pointer = dest;

  if (base == 0)
    base = 10;
  else if (base == 10 && (int)number < 0) {
    number = ~number + 1;  // reverse bytes for negative number
    is_negative = 1;       // set negative flag
  }

  do {
    *string_pointer++ = s21_number_to_char(
        number % base, hight);  // get remainder of div and add to result string
    number /= base;
  } while (number != 0);  // fill string with number

  if (base == 10 && is_negative)
    *string_pointer++ = '-';  // set '-' for negative decimal number
  *string_pointer = '\0';     // set end of string
  s21_reverse_string(dest);

  return dest;
}
char *s21_long_to_string(char *dest, unsigned long number, int base,
                         int hight) {
  int is_negative = 0;  // flag negative number
  char *string_pointer = dest;

  if (base == 0)
    base = 10;  // for %u(unsigned number)
  else if (base == 10 && (long)number < 0) {
    number = ~number + 1;  // reverse bytes for negative number
    is_negative = 1;       // set negative flag
  }

  do {
    *string_pointer++ = s21_number_to_char(
        number % base, hight);  // get remainder of div and add to result string
    number /= base;
  } while (number != 0);  // fill string with number

  if (base == 10 && is_negative)
    *string_pointer++ = '-';  // set '-' for negative decimal number
  *string_pointer = '\0';     // set end of string
  s21_reverse_string(dest);

  return dest;
}

char s21_number_to_char(int number, int hight) {
  char ch = '?';
  int shift = 0;
  if (!hight) shift = 'a' - 'A';
  if (number > -1 && number < 10) ch = number + '0';
  if (number > 9 && number < 16) ch = number + shift + 55;

  return ch;
}

// char *s21_double_to_string(char *dest, long double number, int accuracy) {
//   char *string_pointer = dest;

//   dest = s21_long_to_string(dest, (long)number, 10,
//                             LOW_CASE);  // get integer part of number
//   if (number < 0) number *= -1.0;       // get positiv number
//   while (*string_pointer != '\0')
//     string_pointer++;  // set pointer at the end of integer number
//   *string_pointer++ = '.';
//   for (int i = 0; i < accuracy; i++) {
//     number *= 10.0;  // get next number after dot
//     *string_pointer++ = s21_number_to_char(
//         (long)number % 10, LOW_CASE);  // add this nember to string
//   }
//   *string_pointer = '\0';  // set end of string

//   return dest;
// }

char *s21_double_to_notation(char *dest, long double number, int accuracy,
                             int hight) {
  char *string_pointer = dest;
  int end = 0;

  if ((long)number == 0 && number != 0) {
    while ((long)number == 0) {
      end--;
      number *= 10.0;
    }
  } else
    while ((long)number > 1 || (long)number < -1) {
      number /= 10.0;
      end++;
    }

  // changes 1 start
  // dest = s21_double_to_string(dest, number, accuracy);
  s21_doubleToString(number, dest, accuracy, 0);
  // changes 1 end
  // printf("dest: %s\n", dest);
  int flag_displacement = 0;
  // printf("accuracy = %d\n", accuracy);
  // printf("number * 10 = %Lf\n", number*10);
  if ((dest[0] == '0' || (dest[0] == '-' && dest[1] == '0')) &&
      s21_strlen(dest) > 3) {
    for (int i = 0; (s21_size_t int)i < s21_strlen(dest) + 1; i++)
      dest[i] = '\0';
    s21_doubleToString(number * 10, dest, accuracy, 0);
    flag_displacement = 1;
  }
  // printf("dest:%s\n", dest);

  while (*string_pointer != '\0') string_pointer++;

  if (hight)
    *string_pointer++ = 'E';
  else
    *string_pointer++ = 'e';

  if (end < 0) {
    *string_pointer++ = '-';
    end *= -1;
  } else
    *string_pointer++ = '+';

  // changes 2 start
  if (flag_displacement == 1 && number != 0) end--;

  char *end_string = calloc(MAX_LEN_NUMBER, sizeof(char));
  s21_int_to_string(end_string, end, 10, LOW_CASE);
  if (s21_strlen(end_string) == 1) {
    end_string[2] = '\0';
    end_string[1] = end_string[0];
    end_string[0] = '0';
  }

  for (int i = 0; (s21_size_t int)i < s21_strlen(end_string); i++) {
    *string_pointer++ = end_string[i];
  }
  free(end_string);

  // changes 2 end

  *string_pointer = '\0';
  return dest;
}

char *s21_reverse_string(char *p) {
  s21_size_t len = s21_strlen(p) - 1;
  char c;
  for (s21_size_t i = 0; i < len; i++, len--) {
    c = *(p + i);
    *(p + i) = *(p + len);
    *(p + len) = c;
  }

  return p;
}

void *s21_to_upper(const char *str) {
  s21_size_t int i;
  int bool = 0;
  // char *upperstr = (char *)calloc(s21_strlen(str) + 1, sizeof(char));
  static char upperstr[MAX_STRING_LEN] = {'\0'};
  for (i = 0; i < s21_strlen(str); i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      upperstr[i] = str[i] - 32;
    } else {
      upperstr[i] = str[i];
    }
    // i++;
  }

  for (s21_size_t i = 0; i < s21_strlen(upperstr); i++) {
    if ((upperstr[i] < 0)) {
      bool = 1;
    }
  }
  if (s21_strlen(upperstr) < 1) {
    bool = 1;
  }

  // printf("Test1\n%s", upperstr);
  upperstr[i] = '\0';
  // printf("Test 2\n%s", upperstr);
  return bool == 1 ? s21_NULL : &upperstr;

  // free(upperstr);
}

void *s21_to_lower(const char *str) {
  s21_size_t int i;
  int bool = 0;
  // char *upperstr = (char *)calloc(s21_strlen(str) + 1, sizeof(char));
  static char lowerstr[MAX_STRING_LEN] = {'\0'};
  for (i = 0; i < s21_strlen(str); i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      lowerstr[i] = str[i] + 32;
    } else {
      lowerstr[i] = str[i];
    }
    // i++;
  }

  for (s21_size_t i = 0; i < s21_strlen(lowerstr); i++) {
    if ((lowerstr[i] < 0)) {
      bool = 1;
    }
  }
  if (s21_strlen(lowerstr) < 1) {
    bool = 1;
  }

  // printf("Test1\n%s", upperstr);
  lowerstr[i] = '\0';
  // printf("Test 2\n%s", upperstr);
  return bool == 1 ? s21_NULL : &lowerstr;

  // free(upperstr);
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  s21_size_t src_len = s21_strlen(src);
  s21_size_t str_len = s21_strlen(str);

  int bool = 0;
  // Выделение памяти для новой строки
  static char new_str[MAX_STRING_LEN] = {'\0'};

  // Проверяем на корректность индекса
  if (start_index > src_len)
    bool = 1;
  else {
    // Вычилсение общей длины нвоой строки
    s21_size_t new_len = src_len + str_len;

    // Копирование исходной строки до указанного индекса
    s21_strncpy(new_str, src, start_index);
    // Копирование вставляемой строки
    s21_strncpy(new_str + start_index, str, str_len);
    // Копирование оставшейся части исходной строки
    s21_strncpy(new_str + start_index + str_len, src + start_index,
                src_len - start_index);
    // Добавление завершающего нулевого символа
    new_str[new_len] = '\0';
  }

  return bool == 1 ? s21_NULL : &new_str;
}

void *s21_trim(const char *src, const char *trim_chars) {
  // Create a new string and copy the required part from the source string
  static char trimmed_str[MAX_STRING_LEN] = {'\0'};
  int bool = 0;
  if (s21_strlen(src) < 1 || s21_strlen(trim_chars) < 1)
    bool = 1;
  else {
    if (src == s21_NULL || trim_chars == s21_NULL) {
      trim_chars = s21_NULL;
    }

    s21_size_t src_len = s21_strlen(src);
    s21_size_t start_index = 0;
    s21_size_t end_index = src_len - 1;

    // Find the index of the first character not in trim_chars at the beginning
    // of the string
    while (start_index < src_len &&
           s21_strchr(trim_chars, src[start_index]) != s21_NULL) {
      start_index++;
    }

    // Find the index of the last character not in trim_chars at the end of the
    // string
    while (end_index > start_index &&
           s21_strchr(trim_chars, src[end_index]) != s21_NULL) {
      end_index--;
    }

    // Calculate the new length of the string after removing characters
    s21_size_t new_len =
        (end_index >= start_index) ? (end_index - start_index + 1) : 0;

    s21_strncpy(trimmed_str, src + start_index, new_len);
    trimmed_str[new_len] = '\0';  // Add the null-terminating character
  }
  return bool == 1 ? s21_NULL : &trimmed_str;

  // free(trimmed_str);
}

char *s21_flag_g_double(char *dest, double number, int accuracy, int is_sharp,
                        int hight) {
  int X = s21_get_power(number);
  int P = accuracy;
  if (P == 0) P++;
  if (P > X && X >= -4) {
    accuracy = P - (X + 1);
    s21_doubleToString(number, dest, accuracy, is_sharp);
    dest = s21_delete_end_null_f(dest);
  } else {
    accuracy = P - 1;
    dest = s21_double_to_notation(dest, number, accuracy, hight);
    dest = s21_delete_end_null_e(dest);
  }

  return dest;
}

char *s21_flag_g_long_double(char *dest, long double number, int accuracy,
                             int is_sharp, int hight) {
  int X = s21_get_power(number);
  int P = accuracy;
  if (P == 0) P++;
  if (P > X && X >= -4) {
    accuracy = P - (X + 1);
    s21_long_doubleToString(number, dest, accuracy, is_sharp);
    dest = s21_delete_end_null_f(dest);
  } else {
    accuracy = P - 1;
    dest = s21_double_to_notation(dest, number, accuracy, hight);
    dest = s21_delete_end_null_e(dest);
  }

  return dest;
}

int s21_get_power(long double number) {
  int result = 0;
  int incr = 0;
  long double multiplier = 0.1;
  number = fabsl(number);
  if ((long)number == 0) {
    multiplier = 10.0;
    incr = -1;
  } else {
    incr = 1;
  }
  if (number == 0.0) {
    result = 0;
  } else
    while ((long)number > 9 || (long)number == 0) {
      result += incr;
      number *= multiplier;
    }
  return result;
}

char *s21_delete_end_null_f(char *dest) {
  char *pointer = dest;
  while (*pointer != 0) pointer++;
  pointer--;
  while (*pointer == '0') {
    *pointer-- = '\0';
  }
  if (*pointer == '.') *pointer = '\0';

  return dest;
}

char *s21_delete_end_null_e(char *dest) {
  char *pointer = dest;
  char *end = NULL;
  while (*pointer != 'e' && *pointer != 'E') pointer++;
  end = pointer--;
  while (*pointer == '0') *pointer-- = '\0';
  if (*pointer == '.') *pointer = '\0';
  if ((pointer + 1) != end) (void)s21_strncat(dest, end, 10);

  return 0;
  return dest;
}
