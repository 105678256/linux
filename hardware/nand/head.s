@******************************************************************************
@ File��head.s
@ ���ܣ�����SDRAM���������Ƶ�SDRAM��Ȼ������SDRAM����ִ��
@******************************************************************************       

.text
.global _start
_start:
ldr		sp,	=4096			@���ö�ջ 
bl		disable_watch_dog		@��WATCH DOG
bl		memsetup			@��ʼ��SDRAM
bl		init_nand			@��ʼ��NAND Flash
ldr		r0, 	=0x30000000		@1.Ŀ���ַ=0x30000000������SDRAM����ʼ��ַ
mov     	r1, 	#4096			@2.  Դ��ַ   = 4096
mov		r2, 	#1024			@3.  ���Ƴ���= 1024(bytes)
bl		nand_read_ll			@����C����nand_read_ll

ldr		sp,	=0x34000000		@���ö�ջ
ldr		lr,	=halt_loop		@���÷��ص�ַ
ldr		pc,	=main			@bָ���blָ��ֻ��ǰ����ת32M�ķ�Χ����������ʹ����pc��ֵ�ķ���������ת
halt_loop:
b		halt_loop
