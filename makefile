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

OBJECTS = helper.o term.o
def = defs.h
CC = gcc
CFLAGS = -g -Wall 

program: main.o
	$(CC) $(CFLAGS) -o program main.o $(OBJECTS) -lcurses -ggdb -g
main.o: $(def) helper.o
helper.o: $(def) term.o
term.o: $(def) 

test.o: test.c
	$(CC) -c $(CFLAGS) -I $(CUNIT_PATH_PREFIX)include/$(CUNIT_DIRECTORY) test.c

tests: helper.o test.c
	gcc -Wall -L $(CUNIT_PATH_PREFIX)lib -I $(CUNIT_PATH_PREFIX)include/$(CUNIT_DIRECTORY) -o test helper.o test.c -lcunit -lcurses

clean:
	rm *.o test program