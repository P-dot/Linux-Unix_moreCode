# Makefile for building demo applications
# by Brian Fraser

# Edit this file to compile extra C files into their own programs

TARGETS= sum_on_thread

CROOS_TOOL = 
CC_CPP = $(CROSS_TOOL)g++
CC_C = $(CROOS_TOOL)gcc

CFLAGS = Wall -g -std=c99 -Werror

all: clean $(TARGETS)

$(TARGETS):
    $(CC_C) $(CFLAGS) $@.c -o $@

clean:
    rm -f $(TARGETS)