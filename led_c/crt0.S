 .text
 .global _start
 _start:
	ldr	sp, =1024*4
	bl 	main
halt_loop:
	b	halt_loop
