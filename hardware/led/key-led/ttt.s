
key_led.bin:     file format binary

Disassembly of section .data:

00000000 <.data>:
   0:	e3a0da01 	mov	sp, #4096	; 0x1000
   4:	eb000000 	bl	0xc
   8:	eafffffe 	b	0x8
   c:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
  10:	e28db000 	add	fp, sp, #0	; 0x0
  14:	e3a03456 	mov	r3, #1442840576	; 0x56000000
  18:	e2833010 	add	r3, r3, #16	; 0x10
  1c:	e3a02b55 	mov	r2, #87040	; 0x15400
  20:	e5832000 	str	r2, [r3]
  24:	e3a02456 	mov	r2, #1442840576	; 0x56000000
  28:	e2822060 	add	r2, r2, #96	; 0x60
  2c:	e3a03456 	mov	r3, #1442840576	; 0x56000000
  30:	e2833060 	add	r3, r3, #96	; 0x60
  34:	e5933000 	ldr	r3, [r3]
  38:	e3c33df3 	bic	r3, r3, #15552	; 0x3cc0
  3c:	e3c33003 	bic	r3, r3, #3	; 0x3
  40:	e5823000 	str	r3, [r2]
  44:	e3a02456 	mov	r2, #1442840576	; 0x56000000
  48:	e2822014 	add	r2, r2, #20	; 0x14
  4c:	e3a03456 	mov	r3, #1442840576	; 0x56000000
  50:	e2833064 	add	r3, r3, #100	; 0x64
  54:	e5933000 	ldr	r3, [r3]
  58:	e2033001 	and	r3, r3, #1	; 0x1
  5c:	e1a01283 	lsl	r1, r3, #5
  60:	e3a03456 	mov	r3, #1442840576	; 0x56000000
  64:	e2833064 	add	r3, r3, #100	; 0x64
  68:	e5933000 	ldr	r3, [r3]
  6c:	e2033008 	and	r3, r3, #8	; 0x8
  70:	e1a03183 	lsl	r3, r3, #3
  74:	e1811003 	orr	r1, r1, r3
  78:	e3a03456 	mov	r3, #1442840576	; 0x56000000
  7c:	e2833064 	add	r3, r3, #100	; 0x64
  80:	e5933000 	ldr	r3, [r3]
  84:	e2033060 	and	r3, r3, #96	; 0x60
  88:	e1a03103 	lsl	r3, r3, #2
  8c:	e1813003 	orr	r3, r1, r3
  90:	e5823000 	str	r3, [r2]
  94:	eaffffea 	b	0x44
