#
# Makefile for building user programs to run on top of Nachos
#
#  Use "make" to build the test executable(s)
#  Use "make clean" to remove .o files and .coff files
#  Use "make distclean" to remove all files produced by make, including
#     the test executables
#
# This is a GNU Makefile.  It must be used with the GNU make program.
# At UW, the GNU make program is /software/gnu/bin/make.
# In many other places it is known as "gmake".
# You may wish to include /software/gnu/bin/ early in your command
# search path, so that you will be using GNU make when you type "make".
#
# Several things to be aware of:
#
#    It should not be necessary to build the test executables for
#     every type of host machine on which Nachos runs.  You should
#     be able to build them once, and then use them regardless of
#     the host machine type.  That is because the test executables
#     run on the simulated MIPS machine, and not on the host.
#
#    However:
#	(1) if you are experiencing problems with the test executables,
#	    it would be prudent to rebuild them on the host machine
#	    on which you are currently running Nachos.  To do this,
#    	    just type "make distclean", and then "make"
#
#	(2) the procedure used to build the test executables does
#	    depend on the host machine you are on.  All of the machine
#	    dependencies are isolated in the Makefile.dep file.
#	    It should be possible to build the test executables on
#	    any MFCF machine.   In the MFCF environment, this makefile
#           should automatically figure out what type of host you are
#	    on, and should use the appropriate procedure.
#           However, if you are working outside the MFCF environment,
#           you will need to build a cross-compiler, build coff2noff,
#           and edit Makefile.dep in this directory before you
#           can build the test programs.
#
#    Nachos assumes that the location of the program startup routine (the
# 	location the kernel jumps to when the program initially starts up)
#       is at location 0.  This means: start.o must be the first .o passed 
# 	to ld, in order for the routine "Start" to be loaded at location 0
#
#    When you make the test programs, you will see messages like these:
#		numsections 3 
#		Loading 3 sections:
#		        ".text", filepos 0xd0, mempos 0x0, size 0x440
#		        ".data", filepos 0x510, mempos 0x440, size 0x0
#		        ".bss", filepos 0x0, mempos 0x440, size 0x12c0
#    These messages are normal.  They come from the coff2noff program.
#    They are useful in that they tell you how big the various parts of your
#     compiled user program are, and where in the address space
#     coff2noff is going to place them.   This information is also
#     recorded in the header of the executable file that coff2noff
#     creates.  See the method AddrSpace::Load (in userprog/addrspace.cc)
#     for an example of how this header is used by the Nachos OS to set up the
#     address space for a new process that will run the executable.
#
#
# Adding New Test Programs:
#
#     You are free to write new test programs, and to modify the
#	existing programs.   If you write a new program, you will
# 	need to modify this makefile so that the new program will
#       get built.
#     You will need to make the following changes for each program
#       you add:
#		(1) add the program's name to PROGRAMS variable definition
#	 	(2) add dependencies and build commands for the new
#			program.  The easiest way to do this is to
#			copy the dependencies and commands for an
#			existing program, and then change the names.
#
#	For example, if you write a test program in foo.c, for which
#	the executable is to be called foo, you should do the following:
#
#	change the PROGRAMS definition to look like this:
#
#		PROGRAMS = halt shell matmult sort foo
#
#	add these dependencies/commands:
#
#		foo.o: foo.c
#			$(CC) $(CFLAGS) -c foo.c
#		foo: foo.o start.o
#			$(LD) $(LDFLAGS) start.o foo.o -o foo.coff
#			$(COFF2NOFF) foo.coff foo
#
#       Be careful when you copy the commands!  The commands
# 	must be indented with a *TAB*, not a bunch of spaces.
#
#
#############################################################################
# Makefile.dep contains all machine-dependent definitions
# If you are trying to build coff2noff somewhere outside
# of the MFCF environment, you will almost certainly want
# to visit and edit Makefile.dep before doing so
#############################################################################

include Makefile.dep

CC = $(GCCDIR)gcc
AS = $(GCCDIR)as
LD = $(GCCDIR)ld

INCDIR =-I../userprog -I../lib
CFLAGS = -G 0 -c $(INCDIR) -B/usr/local/nachos/lib/gcc-lib/decstation-ultrix/2.95.2/ -B/usr/local/nachos/decstation-ultrix/bin/

ifeq ($(hosttype),unknown)
PROGRAMS = unknownhost
else
# change this if you create a new test program!
PROGRAMS = add halt shell matmult sort segments prog1 prog2 prog3 prog4 prog5 prog6 prog7 prog8 prog9 prog0
endif

all: $(PROGRAMS)

start.o: start.S ../userprog/syscall.h
	$(CC) $(CFLAGS) $(ASFLAGS) -c start.S

halt.o: halt.c
	$(CC) $(CFLAGS) -c halt.c
halt: halt.o start.o
	$(LD) $(LDFLAGS) start.o halt.o -o halt.coff
	$(COFF2NOFF) halt.coff halt

add.o: add.c
	$(CC) $(CFLAGS) -c add.c

add: add.o start.o
	$(LD) $(LDFLAGS) start.o add.o -o add.coff
	$(COFF2NOFF) add.coff add

shell.o: shell.c
	$(CC) $(CFLAGS) -c shell.c
shell: shell.o start.o
	$(LD) $(LDFLAGS) start.o shell.o -o shell.coff
	$(COFF2NOFF) shell.coff shell

sort.o: sort.c
	$(CC) $(CFLAGS) -c sort.c
sort: sort.o start.o
	$(LD) $(LDFLAGS) start.o sort.o -o sort.coff
	$(COFF2NOFF) sort.coff sort

segments.o: segments.c
	$(CC) $(CFLAGS) -c segments.c
segments: segments.o start.o
	$(LD) $(LDFLAGS) start.o segments.o -o segments.coff
	$(COFF2NOFF) segments.coff segments

matmult.o: matmult.c
	$(CC) $(CFLAGS) -c matmult.c
matmult: matmult.o start.o
	$(LD) $(LDFLAGS) start.o matmult.o -o matmult.coff
	$(COFF2NOFF) matmult.coff matmult

prog1.o: prog1.c
	$(CC) $(CFLAGS)	-c prog1.c
prog1: prog1.o start.o
	$(LD) $(LDFLAGS) start.o prog1.o -o prog1.coff
	$(COFF2NOFF) prog1.coff prog1
prog2.o: prog2.c
	$(CC) $(CFLAGS)	-c prog2.c
prog2: prog2.o start.o
	$(LD) $(LDFLAGS) start.o prog2.o -o prog2.coff
	$(COFF2NOFF) prog2.coff prog2
prog3.o: prog3.c
	$(CC) $(CFLAGS)	-c prog3.c
prog3: prog3.o start.o
	$(LD) $(LDFLAGS) start.o prog3.o -o prog3.coff
	$(COFF2NOFF) prog3.coff prog3

prog4.o: prog4.c
	$(CC) $(CFLAGS) -c prog4.c
prog4: prog4.o start.o
	$(LD) $(LDFLAGS) start.o prog4.o -o prog4.coff
	$(COFF2NOFF) prog4.coff prog4

prog6.o: prog6.c
	$(CC) $(CFLAGS) -c prog6.c
prog6: prog6.o start.o
	$(LD) $(LDFLAGS) start.o prog6.o -o prog6.coff
	$(COFF2NOFF) prog6.coff prog6

prog5.o: prog5.c
	$(CC) $(CFLAGS) -c prog5.c
prog5: prog5.o start.o
	$(LD) $(LDFLAGS) start.o prog5.o -o prog5.coff
	$(COFF2NOFF) prog5.coff prog5

prog7.o: prog7.c
	$(CC) $(CFLAGS) -c prog7.c
prog7: prog7.o start.o
	$(LD) $(LDFLAGS) start.o prog7.o -o prog7.coff
	$(COFF2NOFF) prog7.coff prog7

prog8.o: prog8.c
	$(CC) $(CFLAGS) -c prog8.c
prog8: prog8.o start.o
	$(LD) $(LDFLAGS) start.o prog8.o -o prog8.coff
	$(COFF2NOFF) prog8.coff prog8

prog9.o: prog9.c
	$(CC) $(CFLAGS) -c prog9.c
prog9: prog9.o start.o
	$(LD) $(LDFLAGS) start.o prog9.o -o prog9.coff
	$(COFF2NOFF) prog9.coff prog9

prog0.o: prog0.c
	$(CC) $(CFLAGS) -c prog0.c
prog0: prog0.o start.o
	$(LD) $(LDFLAGS) start.o prog0.o -o prog0.coff
	$(COFF2NOFF) prog0.coff prog0


clean:
	$(RM) -f *.o *.ii
	$(RM) -f *.coff

distclean: clean
	$(RM) -f $(PROGRAMS)

unknownhost:
	@echo Host type could not be determined.
	@echo make is terminating.
	@echo If you are on an MFCF machine, contact the instructor to report this problem
	@echo Otherwise, edit Makefile.dep and try again.
