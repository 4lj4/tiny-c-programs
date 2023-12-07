/*
    Write "helloworld" to a file
*/
#include "funcs.h"

#define O_WRONLY 01
#define O_CREAT 0100
#define O_TRUNC 01000

void _start(){
    int fd;
    asm_open(fd, "h", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    asm_write(fd, "helloworld", 11);
    asm_close(fd);
    asm_exit();
}