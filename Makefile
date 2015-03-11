#Makefile

OBJS = test.o
LDLIBS = 
EXEC = test
CFLAGS = -ggdb -Wall
HEADERS = 
SOURCE=src

#cd src

#all : foo
#.PHONY : all

test: $(OBJS)
	cd src; g++ -o $(EXEC) $(OBJS) $(HEADERS) $(LDLIBS)

#foo.o: bar.o baz.o

%.o: %.c
	cd src; g++ -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)

#untested!
#install: foo
#	install -m 644 foo /$(HOME)/bin
#.PHONY: install