/*
    How to compile the smallest file possible:
        tcc main.c -nostdlib -c
        ld.gold main.o -o main
        strip --strip-all main
        objcopy --strip-section-headers main main
    Other notes:
        "a": %rax
        "b": %rbx
        "c": %rcx
        "d": %rdx
        "D": %rdi
        "S": %rsi
        "d": %rdx
*/


#define asm_read(fd, buf, size) asm("syscall" \
                                    : \
                                    :"a"(0),"D"(fd),"S"(buf),"d"(size) \
) // rax == 0 == read syscall // rdi == 0 == stdin fd // rsi == buf ptr // rdx == buf size

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
                          :"a"(fd)\
) // rax == 3 == close syscall // rdi == fd

#define asm_exit() asm("mov $1,%eax;" \
                       "xor %ebx,%ebx;" \
                       "int $0x80" \
) // eax == 1 == exit interrupt // ebx == 0 == exit code 0 (noerr)
