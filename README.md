# INMPIW
A wrapper of the MPI library to allow for easy distribution of executables
that are pre-compiled without being aware of the runtime MPI implementation's
intrinsics and constants.

This is the case when one wants to distribute a binary executable that relies
on the MPI library, but the author cannot build (or does not want to build)
the executable on the target system. This situation arises when the author
does not wish to transfer the source code to the target system. Compiling on
a similar installation of the target MPI library implementation may _not_
work properly. For this reason, this wrapper exists.

This software is meant to be compiled on the target system where code will
be executed. The running code can be compiled --for the same architecture-- on
a system that is not aware of the exact implementation of the MPI library that
lives on the target system. (The .h files that came with the target system's
MPI library installation are not needed when the executable is built.) Three
steps should be involved: (1) building on a given system the running code
against a local installation of the INMPIW library, (2) compiling and running
the "query" code on the target system to create remote .h files, (3) building
the remote INMPIW library. Through this process, the source of the running
code is only built on the local system, but it will execute just fine on the
remote system.

IN 2019/06/07
