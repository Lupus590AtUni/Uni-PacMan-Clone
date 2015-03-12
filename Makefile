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
	#g++ -o $(EXEC) $(OBJS) $(HEADERS) $(LDLIBS) -i $(PATH)/$(FILES)
	g++ -o $(EXEC) $(OBJS) -i $(HEADERS) $(LIBS) $(PATH)/$(FILES) 

*.o: $(PATH)/$(FILES)
	g++ -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)
