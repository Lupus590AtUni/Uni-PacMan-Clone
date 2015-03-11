#Makefile

OBJS = test.o
LDLIBS = 
EXEC = test
CFLAGS = -ggdb -Wall
HEADERS = 

#all : foo
#.PHONY : all

test: $(OBJS)
	src/gcc -o $(EXEC) $(OBJS) $(HEADERS) $(LDLIBS)

#foo.o: bar.o baz.o

%.o: %.c
	src/gcc -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)

#untested!
#install: foo
#	install -m 644 foo /$(HOME)/bin
#.PHONY: install