#define asmWrite(str, len) asm("int $0x80;"::"a"(4),"b"(1),"c"(str),"d"(len))
#define asmExit() asm("mov $1,%eax;xor %ebx,%ebx;int $0x80")

__attribute__((force_align_arg_pointer))
void _start(){
    asmWrite("helloworld", 11);
    asmExit();
}
