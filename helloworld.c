/*
    A nice simple hello world!
*/
#include "syscall-macros.h"

void _start(){
    asm_write(1, "helloworld", 11);
    asm_exit();
}