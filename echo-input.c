/*
    Echo user input N times
*/
#include "funcs.h"

#define N 5

void _start(){
    char buf[256];
    asm_read(buf, 256);
    int i = 0;
    while(i++ < N){
        asm_write(buf, 256);
    }
    asm_exit();
}