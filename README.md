# INMPIW
A wrapper of the MPI library to allow for easy distribution of executables
that are pre-compiled without being aware of the final MPI implementation's
intrinsics and constants.

This software is meant to be compiled on the target system where code will
be executed. The code can be compiled --for the same architecture-- on a
system that is not aware of the exact implementation of the MPI library
that lives on the target system. (The .f files that came with the target
system's MPI library installation are not needed when the executable is
built.)

IN 2019/06/07
