#include "funcs.h"

void _start(){
    char buf[256];
    asm_read(buf, 256);
    int i = 0;
    while(i++ < 5){
        asm_write(buf, 256);
    }
    asm_exit();
}
