
key_led:     file format binary

Disassembly of section .data:

00000000 <.data>:
   0:	e3a0da01 	mov	sp, #4096	; 0x1000
   4:	eb000000 	bl	0xc
   8:	eafffffe 	b	0x8
   c:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
  10:	e28db000 	add	fp, sp, #0	; 0x0
  14:	e24dd00c 	sub	sp, sp, #12	; 0xc
  18:	e3a03456 	mov	r3, #1442840576	; 0x56000000
  1c:	e2833010 	add	r3, r3, #16	; 0x10
  20:	e3a02b55 	mov	r2, #87040	; 0x15400
  24:	e5832000 	str	r2, [r3]
  28:	e3a02456 	mov	r2, #1442840576	; 0x56000000
  2c:	e2822060 	add	r2, r2, #96	; 0x60
  30:	e3a03456 	mov	r3, #1442840576	; 0x56000000
  34:	e2833060 	add	r3, r3, #96	; 0x60
  38:	e5933000 	ldr	r3, [r3]
  3c:	e3c33df3 	bic	r3, r3, #15552	; 0x3cc0
  40:	e3c33003 	bic	r3, r3, #3	; 0x3
  44:	e5823000 	str	r3, [r2]
  48:	e3a02456 	mov	r2, #1442840576	; 0x56000000
  4c:	e2822014 	add	r2, r2, #20	; 0x14
  50:	e3a03456 	mov	r3, #1442840576	; 0x56000000
  54:	e2833064 	add	r3, r3, #100	; 0x64
  58:	e5933000 	ldr	r3, [r3]
  5c:	e2033001 	and	r3, r3, #1	; 0x1
  60:	e1a01283 	lsl	r1, r3, #5
  64:	e3a03456 	mov	r3, #1442840576	; 0x56000000
  68:	e2833064 	add	r3, r3, #100	; 0x64
  6c:	e5933000 	ldr	r3, [r3]
  70:	e2033008 	and	r3, r3, #8	; 0x8
  74:	e1a03183 	lsl	r3, r3, #3
  78:	e1811003 	orr	r1, r1, r3
  7c:	e3a03456 	mov	r3, #1442840576	; 0x56000000
  80:	e2833064 	add	r3, r3, #100	; 0x64
  84:	e5933000 	ldr	r3, [r3]
  88:	e2033060 	and	r3, r3, #96	; 0x60
  8c:	e1a03103 	lsl	r3, r3, #2
  90:	e1813003 	orr	r3, r1, r3
  94:	e5823000 	str	r3, [r2]
  98:	eaffffea 	b	0x48
