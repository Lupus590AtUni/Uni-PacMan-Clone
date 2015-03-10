

OBJS = refs.o
LDLIBS = 
EXEC = refs
CFLAGS = -ggdb -Wall
HEADERS = 

$(EXEC): $(OBJS)
	g++ -o $(EXEC) $(OBJS) $(HEADERS) $(LDLIBS)
	#gcc -o $(EXEC) $(OBJS) $(HEADERS) $(LDLIBS)
#foo.o: bar.o baz.o

%.o: %.c
	g++ -c $(CFLAGS) $< -o $@
	#gcc -c $(CFLAGS) $< -o $@ - need c++ headers

clean:
	rm -f $(OBJS) $(EXEC)