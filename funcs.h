/*
    How to compile the smallest file possible:
        tcc main.c -nostdlib -c
        ld.gold main.o -o main
        strip --strip-all main
        objcopy --strip-section-headers main main

    When should I use the macros vs the functions?
        You should use the functions if youre calling it many times, experiment to see at what point it saves space for you to use a function vs inserting macro multiple times
        use #define to switch to functions instead of macros as you need

    Other notes:
        "a" == rax
        "D" == rdi
        "S" == rsi
        "d" == rdx
*/

/* Enable these to switch from a macro to a real function */
//#define ENABLE_FUNCTION_READ
//#define ENABLE_FUNCTION_WRITE
//#define ENABLE_FUNCTION_EXIT


#define _macro_asm_read(buf, size) asm("syscall" \
                                       : \
                                       :"a"(0),"D"(0),"S"(buf),"d"(size) \
) // rax == 0 == read syscall // rdi == 0 == stdin fd // rsi == buf ptr // rdx == buf size
#ifdef ENABLE_FUNCTION_READ
    void asm_read(char* buf, int size){
        _macro_asm_read(buf, size);
    }
#else
    #define asm_read _macro_asm_read
#endif


#define _macro_asm_write(buf, size) asm("syscall" \
                                        : \
                                        :"a"(1),"D"(1),"S"(buf),"d"(size) \
) // rax == 1 == write syscall // rdi == 1 == stdout fd // rsi == buf ptr // rdx == buf size
#ifdef ENABLE_FUNCTION_WRITE
    void asm_write(char* buf, int size){
        _macro_asm_write(buf, size);
    }
#else
    #define asm_write _macro_asm_write
#endif


#define _macro_asm_exit() asm("mov $1,%eax;" \
                              "xor %ebx,%ebx;" \
                              "int $0x80" \
) // eax == 1 == exit interrupt // ebx == 0 == exit code 0 (noerr)
#ifdef ENABLE_FUNCTION_EXIT
    void asm_exit(){
        _macro_asm_exit();
    }
#else
    #define asm_exit _macro_asm_exit
#endif

