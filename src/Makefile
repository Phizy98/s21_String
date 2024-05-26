CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -std=c11
COVFLAGS = -fprofile-arcs -ftest-coverage
TESTFLAGS = -lcheck
FILES = s21_string.c s21_sprintf.c

all: style

s21_string.a: s21_string.o
	ar rc s21_string.a s21_string.o
	ranlib s21_string.a 
	rm *.o

s21_string.o: s21_string.c s21_string.h
	$(CC) $(CFLAGS) -c s21_string.c -o s21_string.o

s21_sprintf.a: s21_sprintf.o
	ar rc s21_sprintf.a s21_sprintf.o
	ranlib s21_sprintf.a 
	rm *.o

s21_sprintf.o: s21_sprintf.c 
	$(CC) $(CFLAGS) -c s21_sprintf.c -o s21_sprintf.o

test: s21_string.a s21_sprintf.a
	$(CC) $(CFLAGS) s21_test.c s21_string.a s21_sprintf.a $(TESTFLAGS) -o test_rez
	./test_rez
	rm *.a 

gcov_report:
	$(CC) $(CFLAGS) s21_test.c $(FILES) $(TESTFLAGS) $(COVFLAGS) -o test_rez
	./test_rez
	lcov -t "Test_string" -o test_rez.info -c -d .
	genhtml -o report test_rez.info
	rm *.gcda *.gcno *.info
	open report/index.html

style:
	clang-format -i --style=Google *.c *.h

clean:
	rm -rf report
	rm -rf test_rez
	rm -rf *.a
	rm -rf *.o
	rm -rf *.dSYM
	
