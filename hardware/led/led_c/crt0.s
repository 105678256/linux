# 1 "crt0.S"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "crt0.S"
 .text
 .global _start
 _start:
 ldr sp, =1024*4
 bl main
halt_loop:
 b halt_loop
