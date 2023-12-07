/*
    Echo user input N times
*/
#include "syscall-macros.h"

#define N 5

void _start(){
    char buf[256];
    asm_read(0, buf, 256);
    int i = 0;
    while(i++ < N){
        asm_write(1, buf, 256);
    }
    asm_exit();
}
