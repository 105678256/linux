
sdram:     file format binary

Disassembly of section .data:

00000000 <.data>:
   0:	eb000005 	bl	0x1c
   4:	eb000010 	bl	0x4c
   8:	eb000007 	bl	0x2c
   c:	e59ff090 	ldr	pc, [pc, #144]	; 0xa4
  10:	e3a0d30d 	mov	sp, #872415232	; 0x34000000
  14:	eb000033 	bl	0xe8
  18:	eafffffe 	b	0x18
  1c:	e3a01453 	mov	r1, #1392508928	; 0x53000000
  20:	e3a02000 	mov	r2, #0	; 0x0
  24:	e5812000 	str	r2, [r1]
  28:	e1a0f00e 	mov	pc, lr
  2c:	e3a01000 	mov	r1, #0	; 0x0
  30:	e3a02203 	mov	r2, #805306368	; 0x30000000
  34:	e3a03a01 	mov	r3, #4096	; 0x1000
  38:	e4914004 	ldr	r4, [r1], #4
  3c:	e4824004 	str	r4, [r2], #4
  40:	e1510003 	cmp	r1, r3
  44:	1afffffb 	bne	0x38
  48:	e1a0f00e 	mov	pc, lr
  4c:	e3a01312 	mov	r1, #1207959552	; 0x48000000
  50:	e28f2018 	add	r2, pc, #24	; 0x18
  54:	e1a00000 	nop			(mov r0,r0)
  58:	e2813034 	add	r3, r1, #52	; 0x34
  5c:	e4924004 	ldr	r4, [r2], #4
  60:	e4814004 	str	r4, [r1], #4
  64:	e1510003 	cmp	r1, r3
  68:	1afffffb 	bne	0x5c
  6c:	e1a0f00e 	mov	pc, lr
  70:	22111110 	andscs	r1, r1, #4	; 0x4
  74:	00000700 	andeq	r0, r0, r0, lsl #14
  78:	00000700 	andeq	r0, r0, r0, lsl #14
  7c:	00000700 	andeq	r0, r0, r0, lsl #14
  80:	00000700 	andeq	r0, r0, r0, lsl #14
  84:	00000700 	andeq	r0, r0, r0, lsl #14
  88:	00000700 	andeq	r0, r0, r0, lsl #14
  8c:	00018005 	andeq	r8, r1, r5
  90:	00018005 	andeq	r8, r1, r5
  94:	008e07a3 	addeq	r0, lr, r3, lsr #15
  98:	000000b2 	strheq	r0, [r0], -r2
  9c:	00000030 	andeq	r0, r0, r0, lsr r0
  a0:	00000030 	andeq	r0, r0, r0, lsr r0
  a4:	30000010 	andcc	r0, r0, r0, lsl r0
  a8:	e1a00000 	nop			(mov r0,r0)
  ac:	e1a00000 	nop			(mov r0,r0)
  b0:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
  b4:	e28db000 	add	fp, sp, #0	; 0x0
  b8:	e24dd00c 	sub	sp, sp, #12	; 0xc
  bc:	e50b0008 	str	r0, [fp, #-8]
  c0:	ea000002 	b	0xd0
  c4:	e51b3008 	ldr	r3, [fp, #-8]
  c8:	e2433001 	sub	r3, r3, #1	; 0x1
  cc:	e50b3008 	str	r3, [fp, #-8]
  d0:	e51b3008 	ldr	r3, [fp, #-8]
  d4:	e3530000 	cmp	r3, #0	; 0x0
  d8:	1afffff9 	bne	0xc4
  dc:	e28bd000 	add	sp, fp, #0	; 0x0
  e0:	e8bd0800 	pop	{fp}
  e4:	e12fff1e 	bx	lr
  e8:	e92d4800 	push	{fp, lr}
  ec:	e28db004 	add	fp, sp, #4	; 0x4
  f0:	e24dd008 	sub	sp, sp, #8	; 0x8
  f4:	e3a03000 	mov	r3, #0	; 0x0
  f8:	e50b3008 	str	r3, [fp, #-8]
  fc:	e3a03456 	mov	r3, #1442840576	; 0x56000000
 100:	e2833010 	add	r3, r3, #16	; 0x10
 104:	e3a02b55 	mov	r2, #87040	; 0x15400
 108:	e5832000 	str	r2, [r3]
 10c:	e3a00ebb 	mov	r0, #2992	; 0xbb0
 110:	e2800008 	add	r0, r0, #8	; 0x8
 114:	ebffffe5 	bl	0xb0
 118:	e3a02456 	mov	r2, #1442840576	; 0x56000000
 11c:	e2822014 	add	r2, r2, #20	; 0x14
 120:	e51b3008 	ldr	r3, [fp, #-8]
 124:	e1a03283 	lsl	r3, r3, #5
 128:	e1e03003 	mvn	r3, r3
 12c:	e5823000 	str	r3, [r2]
 130:	e51b3008 	ldr	r3, [fp, #-8]
 134:	e2833001 	add	r3, r3, #1	; 0x1
 138:	e50b3008 	str	r3, [fp, #-8]
 13c:	e51b3008 	ldr	r3, [fp, #-8]
 140:	e3530010 	cmp	r3, #16	; 0x10
 144:	1afffff0 	bne	0x10c
 148:	e3a03000 	mov	r3, #0	; 0x0
 14c:	e50b3008 	str	r3, [fp, #-8]
 150:	eaffffed 	b	0x10c
