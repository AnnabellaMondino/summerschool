ifeq ($(COMP),)
COMP=cray
endif

COMMONDIR=../../../heat/common

ifeq ($(COMP),cray)
CC=cc
CCFLAGS=-g -Wall -I/appl/opt/libpng/include -I$(COMMONDIR)
#-fsanitize=address
LDFLAGS=-L/appl/opt/libpng/lib
LIBS=-lpng -lz
endif

ifeq ($(COMP),gnu)
CC=gcc
CCFLAGS=-g -Og -fsanitize=address -Wall -I$(COMMONDIR)
LDFLAGS=
LIBS=-lpng
endif

EXE=heat_serial
OBJS=core.o setup.o utilities.o io.o main.o
OBJS_PNG=$(COMMONDIR)/pngwriter.o


all: $(EXE)

$(COMMONDIR)/pngwriter.o: $(COMMONDIR)/pngwriter.c $(COMMONDIR)/pngwriter.h
core.o: core.c heat.h
utilities.o: utilities.c heat.h
setup.o: setup.c heat.h
io.o: io.c heat.h
main.o: main.c heat.h

$(OBJS_PNG): C_COMPILER := $(CC)
$(OBJS): C_COMPILER := $(CC)

$(EXE): $(OBJS) $(OBJS_PNG)
	$(CC) $(CCFLAGS) $(OBJS) $(OBJS_PNG) -o $@ $(LDFLAGS) $(LIBS)

%.o: %.c
	$(C_COMPILER) $(CCFLAGS) -c $< -o $@

.PHONY: clean
clean:
	-/bin/rm -f $(EXE) a.out *.o *.png *~
