MPICC = mpicc
COPTS = -fPIC -Wall -O0

all:
	$(MPICC) $(COPTS) -c inmpiw.c -D  _DEMO_
	$(MPICC)             inmpiw.o

q:
	$(MPICC) $(COPTS) -D  _OPENMPI_ query.c -o inmpiw_query

clean:
	rm -f *.o a.out *.a *.so
	rm -f inmpiw_query

