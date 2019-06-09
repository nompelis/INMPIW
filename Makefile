MPICC = mpicc
COPTS = -fPIC -Wall -O0

all:
	$(MPICC) $(COPTS) -c inmpiw.c
	$(MPICC)             inmpiw.o
	$(MPICC) $(COPTS) -D  _OPENMPI_ query.c -o inmpiw_query

clean:
	rm -f *.o a.out *.a *.so
	rm -f inmpiw_query

