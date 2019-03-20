# OS identification from: https://stackoverflow.com/questions/714100/os-detecting-makefile
OS := $(shell uname -s)

ifeq ($(OS), Darwin) 
  CUNIT_PATH_PREFIX = /usr/local/Cellar/cunit/2.1-3/
  CUNIT_DIRECTORY = cunit
endif
ifeq ($(OS), Linux) 
  CUNIT_PATH_PREFIX = /usr/
  CUNIT_DIRECTORY = CUnit/
endif

OBJECTS = helper.o main.o term.o
def = defs.h
CC = gcc
FLAGS = -g -Wall -Werror -std=c11

program: main.o
	$(CC) $(FLAGS) -o program main.o
main.o: $(def) helper.o term.o
helper.o: $(def) term.o
term.o: term.c

test.o: test.c
	$(CC) -c $(FLAGS) -I $(CUNIT_PATH_PREFIX)include/$(CUNIT_DIRECTORY) test.c

tests: helper.o test.o
	gcc -Wall -L $(CUNIT_PATH_PREFIX)lib -I $(CUNIT_PATH_PREFIX)include/$(CUNIT_DIRECTORY) -o test helper.o test.o -lcunit

clean:
	rm *.o test program