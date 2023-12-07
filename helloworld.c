#include "funcs.h"

void _start(){
    asm_write("helloworld", 11);
    asm_exit();
}