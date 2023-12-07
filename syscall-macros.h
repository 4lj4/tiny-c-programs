/*
    A collection of macros for writing usable programs without stdlib :)
*/
/*
    "a": %rax
    "b": %rbx
    "c": %rcx
    "d": %rdx
    "D": %rdi
    "S": %rsi
    "d": %rdx
*/

#define asm_read(fd, buf, size) asm("xor %%rax, %%rax;" \
                                    "syscall" \
                                    : \
                                    :"D"(fd),"S"(buf),"d"(size) \
) // rax == 0 == read syscall (we save a couple bytes using xor ;) ) // rdi == fd // rsi == buf ptr // rdx == buf size

#define asm_write(fd, buf, size) asm("syscall" \
                                     : \
                                     :"a"(1),"D"(fd),"S"(buf),"d"(size) \
) // rax == 1 == write syscall // rdi == 1 == stdout fd // rsi == buf ptr // rdx == buf size

#define asm_open(fd, fn, flags, mode) asm("syscall" \
                                         :"=r" (fd) \
                                         :"a"(2),"D"(fn),"S"(flags),"d"(mode) \
) // rax == 2 == open syscall // rdi == filename ptr // rsi == flags // rdx == mode

#define asm_close(fd) asm("syscall" \
                          : \
                          :"a"(3), "D"(fd) \
) // rax == 3 == close syscall // rdi == fd

#define asm_exit() asm("xor %%rdi,%%rdi;" \
                       "syscall" \
                       : \
                       :"a"(60) \
)// rax == 60 == exit syscall // rdi == 0 == no err exit code
