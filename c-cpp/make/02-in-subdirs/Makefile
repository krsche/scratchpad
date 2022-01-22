# Makefile for building into current dir

CC=gcc
CXX=g++
CFLAGS=-g -Wall
CXXFLAGS=$(CFLAGS)

SRC=src
OBJ=obj
SRCS=$(wildcard $(SRC)/*.cpp)
OBJS=$(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))

BINDIR=bin
BIN = $(BINDIR)/main

# create dirs if not existent


all: $(BIN)

release: CFLAGS=-Wall -O2 -DNDEBUG
release: clean
release: $(BIN)

$(BIN): $(OBJS)
	[ -d $(BINDIR) ] || mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.cpp
	[ -d $(OBJ) ] || mkdir -p $(OBJ)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) -r $(BINDIR)/* $(OBJ)/*