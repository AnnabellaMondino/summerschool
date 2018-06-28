
EXE=libpng
OBJS=pngwriter.o libpng.o
LIBS=-L/appl/opt/libpng/lib -lpng -lz

all: $(EXE)

pngwriter.o: pngwriter.c pngwriter.h
libpng.o: libpng.c


$(EXE): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LIBS)

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	-/bin/rm -f $(EXE) a.out *.o *.png

