__attribute__((force_align_arg_pointer))
void _start(){
    asm (
        "int $0x80;"
        :
        :"a"(4),"b"(1),"c"("helloworld"),"d"(11)
    );
    asm(
        "mov $1,%eax;"
        "xor %ebx,%ebx;"
        "int  $0x80"
    );
}
