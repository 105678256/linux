
key_led.bin:     file format binary

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
  30:	e3e03df3 	mvn	r3, #15552	; 0x3cc0
  34:	e2433003 	sub	r3, r3, #3	; 0x3
  38:	e5823000 	str	r3, [r2]
  3c:	e3a02456 	mov	r2, #1442840576	; 0x56000000
  40:	e2822014 	add	r2, r2, #20	; 0x14
  44:	e3a03801 	mov	r3, #65536	; 0x10000
  48:	e2433001 	sub	r3, r3, #1	; 0x1
  4c:	e5823000 	str	r3, [r2]
  50:	e3a03456 	mov	r3, #1442840576	; 0x56000000
  54:	e2833064 	add	r3, r3, #100	; 0x64
  58:	e5933000 	ldr	r3, [r3]
  5c:	e50b3008 	str	r3, [fp, #-8]
  60:	e51b3008 	ldr	r3, [fp, #-8]
  64:	e2033001 	and	r3, r3, #1	; 0x1
  68:	e20330ff 	and	r3, r3, #255	; 0xff
  6c:	e3530000 	cmp	r3, #0	; 0x0
  70:	0a000007 	beq	0x94
  74:	e3a02456 	mov	r2, #1442840576	; 0x56000000
  78:	e2822014 	add	r2, r2, #20	; 0x14
  7c:	e3a03456 	mov	r3, #1442840576	; 0x56000000
  80:	e2833014 	add	r3, r3, #20	; 0x14
  84:	e5933000 	ldr	r3, [r3]
  88:	e3833020 	orr	r3, r3, #32	; 0x20
  8c:	e5823000 	str	r3, [r2]
  90:	ea000006 	b	0xb0
  94:	e3a02456 	mov	r2, #1442840576	; 0x56000000
  98:	e2822014 	add	r2, r2, #20	; 0x14
  9c:	e3a03456 	mov	r3, #1442840576	; 0x56000000
  a0:	e2833014 	add	r3, r3, #20	; 0x14
  a4:	e5933000 	ldr	r3, [r3]
  a8:	e3c33020 	bic	r3, r3, #32	; 0x20
  ac:	e5823000 	str	r3, [r2]
  b0:	e51b3008 	ldr	r3, [fp, #-8]
  b4:	e2033008 	and	r3, r3, #8	; 0x8
  b8:	e3530000 	cmp	r3, #0	; 0x0
  bc:	0a000007 	beq	0xe0
  c0:	e3a02456 	mov	r2, #1442840576	; 0x56000000
  c4:	e2822014 	add	r2, r2, #20	; 0x14
  c8:	e3a03456 	mov	r3, #1442840576	; 0x56000000
  cc:	e2833014 	add	r3, r3, #20	; 0x14
  d0:	e5933000 	ldr	r3, [r3]
  d4:	e3833040 	orr	r3, r3, #64	; 0x40
  d8:	e5823000 	str	r3, [r2]
  dc:	ea000006 	b	0xfc
  e0:	e3a02456 	mov	r2, #1442840576	; 0x56000000
  e4:	e2822014 	add	r2, r2, #20	; 0x14
  e8:	e3a03456 	mov	r3, #1442840576	; 0x56000000
  ec:	e2833014 	add	r3, r3, #20	; 0x14
  f0:	e5933000 	ldr	r3, [r3]
  f4:	e3c33040 	bic	r3, r3, #64	; 0x40
  f8:	e5823000 	str	r3, [r2]
  fc:	e51b3008 	ldr	r3, [fp, #-8]
 100:	e2033020 	and	r3, r3, #32	; 0x20
 104:	e3530000 	cmp	r3, #0	; 0x0
 108:	0a000007 	beq	0x12c
 10c:	e3a02456 	mov	r2, #1442840576	; 0x56000000
 110:	e2822014 	add	r2, r2, #20	; 0x14
 114:	e3a03456 	mov	r3, #1442840576	; 0x56000000
 118:	e2833014 	add	r3, r3, #20	; 0x14
 11c:	e5933000 	ldr	r3, [r3]
 120:	e3833080 	orr	r3, r3, #128	; 0x80
 124:	e5823000 	str	r3, [r2]
 128:	ea000006 	b	0x148
 12c:	e3a02456 	mov	r2, #1442840576	; 0x56000000
 130:	e2822014 	add	r2, r2, #20	; 0x14
 134:	e3a03456 	mov	r3, #1442840576	; 0x56000000
 138:	e2833014 	add	r3, r3, #20	; 0x14
 13c:	e5933000 	ldr	r3, [r3]
 140:	e3c33080 	bic	r3, r3, #128	; 0x80
 144:	e5823000 	str	r3, [r2]
 148:	e51b3008 	ldr	r3, [fp, #-8]
 14c:	e2033040 	and	r3, r3, #64	; 0x40
 150:	e3530000 	cmp	r3, #0	; 0x0
 154:	0a000007 	beq	0x178
 158:	e3a02456 	mov	r2, #1442840576	; 0x56000000
 15c:	e2822014 	add	r2, r2, #20	; 0x14
 160:	e3a03456 	mov	r3, #1442840576	; 0x56000000
 164:	e2833014 	add	r3, r3, #20	; 0x14
 168:	e5933000 	ldr	r3, [r3]
 16c:	e3833c01 	orr	r3, r3, #256	; 0x100
 170:	e5823000 	str	r3, [r2]
 174:	eaffffb5 	b	0x50
 178:	e3a02456 	mov	r2, #1442840576	; 0x56000000
 17c:	e2822014 	add	r2, r2, #20	; 0x14
 180:	e3a03456 	mov	r3, #1442840576	; 0x56000000
 184:	e2833014 	add	r3, r3, #20	; 0x14
 188:	e5933000 	ldr	r3, [r3]
 18c:	e3c33c01 	bic	r3, r3, #256	; 0x100
 190:	e5823000 	str	r3, [r2]
 194:	eaffffad 	b	0x50
