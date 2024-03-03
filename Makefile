# Makefile for the smash program
CXX = g++
CXXFLAGS = -std=c++11 -g -Wall -Werror -pedantic-errors -DNDEBUG
CXXLINK = $(CXX)
OBJS = smash.o commands.o signals.o
RM = rm -f
# Creating the  executable
smash: $(OBJS)
	$(CXXLINK) $(CXXFLAGS) $(OBJS) -o smash
# Creating the object files
smash.o: smash.cpp commands.h signals.h
signals.o: signals.cpp signals.h commands.h
commands.o: commands.cpp commands.h
# Cleaning old files before new make
clean:
	$(RM) *.o smash