@******************************************************************************
@ File：head.s
@ 功能：设置SDRAM，将程序复制到SDRAM，然后跳到SDRAM继续执行
@******************************************************************************       

.text
.global _start
_start:
ldr		sp,	=4096			@设置堆栈 
bl		disable_watch_dog		@关WATCH DOG
bl		memsetup			@初始化SDRAM
bl		init_nand			@初始化NAND Flash
ldr		r0, 	=0x30000000		@1.目标地址=0x30000000，这是SDRAM的起始地址
mov     	r1, 	#4096			@2.  源地址   = 4096
mov		r2, 	#1024			@3.  复制长度= 1024(bytes)
bl		nand_read_ll			@调用C函数nand_read_ll

ldr		sp,	=0x34000000		@设置堆栈
ldr		lr,	=halt_loop		@设置返回地址
ldr		pc,	=main			@b指令和bl指令只能前后跳转32M的范围，所以这里使用向pc赋值的方法进行跳转
halt_loop:
b		halt_loop
