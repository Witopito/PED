.PHONY= doc clean

CC=g++
OPTIONS= -g 
DEBUG= #-D DEBUG
LIBDIR=lib
INCLUDEDIR=include
_OBJ= tcalendario.o tvectorcalendario.o tlistacalendario.o tabbcalendario.o
#tvectorcalendario.o tlistacalendario.o 
OBJ = $(patsubst %,$(LIBDIR)/%,$(_OBJ))

#tad:    src/tad.cpp $(OBJ)
#	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tad.cpp $(OBJ) -o tad

#$(LIBDIR)/%.o : $(LIBDIR)/%.cpp $(INCLUDEDIR)/%.h
#	$(CC) $(OPTIONS) $(DEBUG) -c -I$(INCLUDEDIR) -o $@ $<

#tadcalendario:    src/tadcalendario.cpp $(OBJ)
#	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tadcalendario.cpp $(OBJ) -o tadcalendario

#main:    src/main.cpp $(OBJ)
#	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/main.cpp $(OBJ) -o main
	
main2:    src/main2.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/main2.cpp $(OBJ) -o main2

#$(LIBDIR)/%.o : $(LIBDIR)/%.cpp $(INCLUDEDIR)/%.h
#	$(CC) $(OPTIONS) $(DEBUG) -c -I$(INCLUDEDIR) -o $@ $<

lib/tcalendario.o : lib/tcalendario.cpp include/tcalendario.h
	$(CC) $(OPTIONS) $(DEBUG) -c -I$(INCLUDEDIR) -o $@ $<

lib/tvectorcalendario.o : lib/tvectorcalendario.cpp include/tvectorcalendario.h
	$(CC) $(OPTIONS) $(DEBUG) -c -I$(INCLUDEDIR) -o $@ $<
	
lib/tlistacalendario.o : lib/tlistacalendario.cpp include/tlistacalendario.h
	$(CC) $(OPTIONS) $(DEBUG) -c -I$(INCLUDEDIR) -o $@ $<
	
lib/tabbcalendario.o : lib/tabbcalendario.cpp include/tabbcalendario.h
	$(CC) $(OPTIONS) $(DEBUG) -c -I$(INCLUDEDIR) -o $@ $<

doc:
	doxygen

clean:
	rm -f $(OBJ) 