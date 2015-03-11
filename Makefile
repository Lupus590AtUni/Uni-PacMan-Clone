#Makefile

OBJS = test.o
LDLIBS = 
EXEC = test
CFLAGS = -ggdb -Wall
HEADERS = 
PATH=src
FILES=*.hpp *.cpp


all : test
.PHONY : all

test: $(OBJS)
	g++ -o $(EXEC) $(OBJS) $(HEADERS) $(LDLIBS) -i $(PATH)/$(FILES)

#foo.o: bar.o baz.o

*.o: $(PATH)/$(FILES)
	g++ -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)

#untested!
#install: foo
#	install -m 644 foo /$(HOME)/bin
#.PHONY: install