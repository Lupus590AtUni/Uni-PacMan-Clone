#TODO: put in -g so that gcc keeps the debugging data in, where does the -g go?
#TODO: have a make option that removes the debug info (make deploy , output to deploy folder, will need t update travis to use this command)?




#Needs this to know shell - http://www.cplusplus.com/forum/unices/51045/
#and this to make it right - http://stackoverflow.com/questions/7534572/make-c-command-not-found?rq=1
SHELL:= /bin/bash
LDLIBS = #-L/path -lnameOfDll
EXEC = build/PacMan-Clone.exe
CCFLAGS = -Wall -ggdb
HEADERS = #-I
#Found this here - http://mrbook.org/blog/tutorials/make/
SOURCES:=$(wildcard src/*.cpp)
OBJS:=$(addprefix obj/,$(notdir $(SOURCES:.cpp=.o)))
CXX := g++

#Found this here - http://stackoverflow.com/questions/2908057/makefiles-compile-all-cpp-files-in-src-to-os-in-obj-then-link-to-binary
CC_FLAGS += -MMD
-include $(OBJFILES:.o=.d)

all: test
.PHONY : all

test: $(OBJS)
	$(CXX) -o $(EXEC) $(HEADERS) $(LDLIBS) $^

obj/%.o: src/%.cpp
	$(CXX) $(CCFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) 
	rm -f $(EXEC)
