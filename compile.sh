tcc main.c -nostdlib -c
ld.gold main.o -o main
strip --strip-all main
objcopy --strip-section-headers main main
