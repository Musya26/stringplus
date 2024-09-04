FLAGS = -Wall -Werror -Wextra -std=c11 -g
OS := $(shell uname)
SOURCE = s21_string.c s21_sprintf.c

ifeq ($(OS),Linux)
 OPEN_CMD = xdg-open
 ADD_LIB = -lcheck -lsubunit -lm -lrt -lpthread -D_GNU_SOURSE
endif

ifeq ($(OS),Darwin)
 OPEN_CMD = open
 ADD_LIB = -lcheck
endif

all: s21_string.a test gcov_report clean_gc

test: s21_string.a
	gcc $(FLAGS) tests/*.c s21_string.a -o test $(ADD_LIB)
	./test

s21_string.a:
	gcc -c $(FLAGS) $(SOURCE) 
	ar rcs s21_string.a *.o 

gcov_report:
	gcc --coverage $(SOURCE) tests/*.c -o test $(ADD_LIB)
	./test
	gcov s21_string.c
	lcov -t "stest" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	open ./report/index.html

clean:
	rm -f test
	rm -f *.gc*
	rm -f s21_test.info
	rm -rf report
	rm -f *.o *.a

clean_gc:
	rm -f *.gc* *.o *.info test

format:
	clang-format -style=Google -i *.c *.h

.PHONY: all test s21_string.a gcov_report clean format
