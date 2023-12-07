/*
    A nice simple hello world!
*/
#include "funcs.h"

void _start(){
    asm_write(1, "helloworld", 11);
    asm_exit();
}