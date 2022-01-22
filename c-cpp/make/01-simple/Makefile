# Makefile for building into current dir

CC=gcc
CXX=g++
CFLAGS=-g -Wall
CXXFLAGS=$(CFLAGS)
OBJS=main.o
BIN=main

all:$(BIN)

main: $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o main

%.o: %.c %.cpp %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) -r main *.o