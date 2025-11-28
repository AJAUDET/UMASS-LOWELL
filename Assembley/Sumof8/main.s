	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 15, 0	sdk_version 15, 5
	.globl	_sum_of_8                       ; -- Begin function sum_of_8
	.p2align	2
_sum_of_8:                              ; @sum_of_8
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	.cfi_def_cfa_offset 32
	str	w0, [sp, #28]
	str	w1, [sp, #24]
	str	w2, [sp, #20]
	str	w3, [sp, #16]
	str	w4, [sp, #12]
	str	w5, [sp, #8]
	str	w6, [sp, #4]
	str	w7, [sp]
	ldr	w8, [sp, #28]
	ldr	w9, [sp, #24]
	add	w8, w8, w9
	ldr	w9, [sp, #20]
	add	w8, w8, w9
	ldr	w9, [sp, #16]
	add	w8, w8, w9
	ldr	w9, [sp, #12]
	add	w8, w8, w9
	ldr	w9, [sp, #8]
	add	w8, w8, w9
	ldr	w9, [sp, #4]
	add	w8, w8, w9
	ldr	w9, [sp]
	add	w0, w8, w9
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #64
	stp	x29, x30, [sp, #48]             ; 16-byte Folded Spill
	add	x29, sp, #48
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	mov	w8, #0                          ; =0x0
	str	w8, [sp, #8]                    ; 4-byte Folded Spill
	stur	wzr, [x29, #-4]
	mov	w8, #1                          ; =0x1
	stur	w8, [x29, #-8]
	mov	w8, #2                          ; =0x2
	stur	w8, [x29, #-12]
	mov	w8, #3                          ; =0x3
	stur	w8, [x29, #-16]
	mov	w8, #4                          ; =0x4
	stur	w8, [x29, #-20]
	mov	w8, #5                          ; =0x5
	str	w8, [sp, #24]
	mov	w8, #6                          ; =0x6
	str	w8, [sp, #20]
	mov	w8, #7                          ; =0x7
	str	w8, [sp, #16]
	mov	w8, #8                          ; =0x8
	str	w8, [sp, #12]
	ldur	w0, [x29, #-8]
	ldur	w1, [x29, #-12]
	ldur	w2, [x29, #-16]
	ldur	w3, [x29, #-20]
	ldr	w4, [sp, #24]
	ldr	w5, [sp, #20]
	ldr	w6, [sp, #16]
	ldr	w7, [sp, #12]
	bl	_sum_of_8
	mov	x9, sp
                                        ; implicit-def: $x8
	mov	x8, x0
	str	x8, [x9]
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	ldr	w0, [sp, #8]                    ; 4-byte Folded Reload
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	add	sp, sp, #64
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"The sum is: %d"

.subsections_via_symbols
