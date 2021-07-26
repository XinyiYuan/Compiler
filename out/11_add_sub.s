	.file   "11_add_sub.cact"
	.option nopic
	.attribute arch, "rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	
	.text
	.text
	.align   1
	.globl   main
	.type    main, @function
main:
#frame size:192
	addi    sp,sp,-192
	sd      ra,184(sp)
	sd      s0,176(sp)
	addi    s0,sp,192
	li   t2, 0
	sw   t2, -20(s0)
	li   t2, 0
	sw   t2, -24(s0)
	li   t2, 0
	sw   t2, -28(s0)
	li   t2, 0
	sw   t2, -32(s0)
	call     get_int
	nop
	mv   t2,a0
	sw   t2, -36(s0)
	lw   t2, -36(s0)
	sw   t2, -20(s0)
	li   t2, 3
	sw   t2, -40(s0)
	lw   t0, -20(s0)
	lw   t1, -40(s0)
	subw   t2,t0,t1
	sw   t2, -44(s0)
	lw   t2, -44(s0)
	sw   t2, -24(s0)
	call     get_int
	nop
	mv   t2,a0
	sw   t2, -48(s0)
	lw   t2, -48(s0)
	sw   t2, -28(s0)
	li   t2, 2
	sw   t2, -52(s0)
	lw   t0, -28(s0)
	lw   t1, -52(s0)
	addw   t2,t0,t1
	sw   t2, -56(s0)
	lw   t2, -56(s0)
	sw   t2, -32(s0)
	lw   a0, -24(s0)
	call     print_int
	nop
	lw   a0, -32(s0)
	call     print_int
	nop
	lui  a5,%hi(.LC0)
	flw  ft2,%lo(.LC0)(a5)
	fsw   ft2, -60(s0)
	lui  a5,%hi(.LC1)
	flw  ft2,%lo(.LC1)(a5)
	fsw   ft2, -64(s0)
	lui  a5,%hi(.LC2)
	flw  ft2,%lo(.LC2)(a5)
	fsw   ft2, -68(s0)
	lui  a5,%hi(.LC3)
	flw  ft2,%lo(.LC3)(a5)
	fsw   ft2, -72(s0)
	call     get_float
	nop
	fmv.s   ft2,fa0
	fsw   ft2, -76(s0)
	flw   ft2, -76(s0)
	fsw   ft2, -60(s0)
	lui  a5,%hi(.LC4)
	flw  ft2,%lo(.LC4)(a5)
	fsw   ft2, -80(s0)
	flw   ft0, -60(s0)
	flw   ft1, -80(s0)
	fsub.s   ft2,ft0,ft1
	fsw   ft2, -84(s0)
	flw   ft2, -84(s0)
	fsw   ft2, -64(s0)
	call     get_float
	nop
	fmv.s   ft2,fa0
	fsw   ft2, -88(s0)
	flw   ft2, -88(s0)
	fsw   ft2, -68(s0)
	lui  a5,%hi(.LC5)
	flw  ft2,%lo(.LC5)(a5)
	fsw   ft2, -92(s0)
	flw   ft0, -68(s0)
	flw   ft1, -92(s0)
	fadd.s   ft2,ft0,ft1
	fsw   ft2, -96(s0)
	flw   ft2, -96(s0)
	fsw   ft2, -72(s0)
	flw   fa0, -64(s0)
	call     print_float
	nop
	flw   fa0, -72(s0)
	call     print_float
	nop
	lui  a5,%hi(.LC6)
	fld  ft2,%lo(.LC6)(a5)
	fsd   ft2, -104(s0)
	lui  a5,%hi(.LC7)
	fld  ft2,%lo(.LC7)(a5)
	fsd   ft2, -112(s0)
	lui  a5,%hi(.LC8)
	fld  ft2,%lo(.LC8)(a5)
	fsd   ft2, -120(s0)
	lui  a5,%hi(.LC9)
	fld  ft2,%lo(.LC9)(a5)
	fsd   ft2, -128(s0)
	call     get_double
	nop
	fmv.d   ft2,fa0
	fsd   ft2, -136(s0)
	fld   ft2, -136(s0)
	fsd   ft2, -104(s0)
	lui  a5,%hi(.LC10)
	fld  ft2,%lo(.LC10)(a5)
	fsd   ft2, -144(s0)
	fld   ft0, -104(s0)
	fld   ft1, -144(s0)
	fsub.d   ft2,ft0,ft1
	fsd   ft2, -152(s0)
	fld   ft2, -152(s0)
	fsd   ft2, -112(s0)
	call     get_double
	nop
	fmv.d   ft2,fa0
	fsd   ft2, -160(s0)
	fld   ft2, -160(s0)
	fsd   ft2, -120(s0)
	lui  a5,%hi(.LC11)
	fld  ft2,%lo(.LC11)(a5)
	fsd   ft2, -168(s0)
	fld   ft0, -120(s0)
	fld   ft1, -168(s0)
	fadd.d   ft2,ft0,ft1
	fsd   ft2, -176(s0)
	fld   ft2, -176(s0)
	fsd   ft2, -128(s0)
	fld   fa0, -112(s0)
	call     print_double
	nop
	fld   fa0, -128(s0)
	call     print_double
	nop
	li   t2, 0
	sw   t2, -180(s0)
	lw   a0, -180(s0)
	ld      ra,184(sp)
	ld      s0,176(sp)
	addi    sp,sp,192
	jr ra
	.size   main,.-main
	.section .rodata
	.align  2
.LC0:
	.word    0
	.align  2
.LC1:
	.word    0
	.align  2
.LC2:
	.word    0
	.align  2
.LC3:
	.word    0
	.align  2
.LC4:
	.word    1078774989
	.align  2
.LC5:
	.word    1075000115
	.align  3
.LC6:
	.word    0
	.word    0
	.align  3
.LC7:
	.word    0
	.word    0
	.align  3
.LC8:
	.word    0
	.word    0
	.align  3
.LC9:
	.word    0
	.word    0
	.align  3
.LC10:
	.word    858993459
	.word    1074475827
	.align  3
.LC11:
	.word    -858993459
	.word    1073794252
