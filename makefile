# compiler to use
CC = clang

# flags to pass compiler
CFLAGS = -ggdb3 -O0 -std=c11 -Wall -Werror

# name for executable
EXE = calculator

# space-separated list of header files
HDRS = types.h uiFunc.h brain.h uiFunc.h

# space-separated list of libraries, if any,
# each of which should be prefixed with -l
LIBS =

# space-separated list of source files
SRCS = main.c brain.c uiFunc.c

# automatically generated list of object files
OBJS = $(SRCS:.c=.o)


# default target
$(EXE): $(OBJS) $(HDRS) Makefile
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

# dependencies 
$(OBJS): $(HDRS) Makefile

# housekeeping
clean:
	rm -f core $(EXE) *.o
