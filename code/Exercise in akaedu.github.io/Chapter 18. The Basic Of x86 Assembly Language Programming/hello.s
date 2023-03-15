#PURPOSE: Simple program that exits and returns a
#         status code back to the Linux kernel
#
#INPUT:   none
#
#OUTPUT:  returns a status code. This can be viewed
#         by typing
#
#         echo $?
#
#         after running the program
#
#VARIABLES:
#         %eax holds the system call number
#         %ebx holds the return status
#
 .section .data # Assembler Directive or Pseudo-operation
                # read/write : global variable
 .section .text # read/executable : program code
 .globl _start
_start:         # Symbol : Address
 movl $1, %eax  # this is the linux kernel command
                # number (system call) for exiting
                # a program

 movl $4, %ebx  # this is the status number we will
                # return to the operating system.
                # Change this around and it will
                # return different things to
                # echo $?

 int $0x80      # this wakes up the kernel to run
                # the exit command

# as hello.s -o hello.o # Assembler
# ld hello.0 -o hello   # Linker
