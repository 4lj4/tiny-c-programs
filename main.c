__attribute__((force_align_arg_pointer))
void _start(){
    asm("mov $1,%eax;"
        "xor %ebx,%ebx;"
        "int  $0x80"
    );
}
