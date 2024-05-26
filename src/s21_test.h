#ifndef TEST_S21_STRIING_H
#define TEST_S21_STRIING_H

#define CK_FORK no
#define STR_LEN 512

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

Suite *memchr_suite(void);
Suite *memcmp_suite(void);
Suite *memset_suite(void);
Suite *strncat_suite(void);
Suite *strlen_suite(void);
Suite *strcspn_suite(void);
Suite *strchr_suite(void);
Suite *strncmp_suite(void);
Suite *strncpy_suite(void);
Suite *strpbrk_suite(void);
Suite *strrchr_suite(void);
Suite *strstr_suite(void);
Suite *strtok_suite(void);
Suite *sprintf_c_suite(void);
Suite *sprintf_d_suite(void);
Suite *sprintf_s_suite(void);
Suite *sprintf_u_suite(void);
Suite *sprintf_i_suite(void);
Suite *sprintf_o_suite(void);
Suite *sprintf_x_suite(void);
Suite *sprintf_p_suite(void);
Suite *sprintf_n_suite(void);
Suite *sprintf_f_suite(void);
Suite *sprintf_e_suite(void);
Suite *sprintf_empty_suite(void);
Suite *sprintf_procent_suite(void);

Suite *s21_to_upper_suite(void);
Suite *s21_to_lower_suite(void);
Suite *s21_insert_suite(void);
Suite *s21_trim_suite(void);

// Suite *strerror_suite(void);

#endif

// gcc s21_sprintf.c s21_string.c s21_test.c -lcheck -fprofile-arcs
// -ftest-coverage -o test_rez
// ./test_rez

// lcov -t "STRING_TEST" -o test_rez.info -c -d .

// genhtml -o report test_rez.info
// open report/index.html
