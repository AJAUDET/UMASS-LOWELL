	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 15, 0	sdk_version 15, 5
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	mov	w0, #24                         ; =0x18
	bl	_malloc
	cbz	x0, LBB0_2
; %bb.1:
	mov	w8, #1                          ; =0x1
	str	w8, [x0]
	stp	xzr, xzr, [x0, #8]
	mov	w1, #7                          ; =0x7
	bl	_tree_insert
	mov	w1, #3                          ; =0x3
	bl	_tree_insert
	mov	w1, #4                          ; =0x4
	bl	_tree_insert
	mov	w1, #8                          ; =0x8
	bl	_tree_insert
	mov	w1, #0                          ; =0x0
	bl	_tree_insert
	mov	w1, #6                          ; =0x6
	bl	_tree_insert
	mov	w1, #2                          ; =0x2
	bl	_tree_insert
	mov	w1, #5                          ; =0x5
	bl	_tree_insert
	mov	w1, #9                          ; =0x9
	bl	_tree_insert
	bl	_print_in_order_traversal
	mov	w0, #0                          ; =0x0
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
LBB0_2:
	mov	w8, #1                          ; =0x1
	str	x8, [sp]
Lloh0:
	adrp	x0, l_.str@PAGE
Lloh1:
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	mov	w0, #1                          ; =0x1
	bl	_exit
	.loh AdrpAdd	Lloh0, Lloh1
	.cfi_endproc
                                        ; -- End function
	.globl	_tree_insert                    ; -- Begin function tree_insert
	.p2align	2
_tree_insert:                           ; @tree_insert
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	stp	x20, x19, [sp, #16]             ; 16-byte Folded Spill
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_offset w19, -24
	.cfi_offset w20, -32
	mov	x19, x1
	cbz	x0, LBB1_3
; %bb.1:
	ldr	w8, [x0]
	cmp	w8, w19
	b.le	LBB1_5
; %bb.2:
	ldr	x8, [x0, #8]
	mov	x20, x0
	mov	x0, x8
	mov	x1, x19
	bl	_tree_insert
	mov	x8, x0
	mov	x0, x20
	str	x8, [x20, #8]
	b	LBB1_7
LBB1_3:
	mov	w0, #24                         ; =0x18
	bl	_malloc
	cbz	x0, LBB1_8
; %bb.4:
	str	w19, [x0]
	stp	xzr, xzr, [x0, #8]
	b	LBB1_7
LBB1_5:
	b.ge	LBB1_7
; %bb.6:
	ldr	x8, [x0, #16]
	mov	x20, x0
	mov	x0, x8
	mov	x1, x19
	bl	_tree_insert
	mov	x8, x0
	mov	x0, x20
	str	x8, [x20, #16]
LBB1_7:
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	ldp	x20, x19, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
LBB1_8:
	str	x19, [sp]
Lloh2:
	adrp	x0, l_.str@PAGE
Lloh3:
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	mov	w0, #1                          ; =0x1
	bl	_exit
	.loh AdrpAdd	Lloh2, Lloh3
	.cfi_endproc
                                        ; -- End function
	.globl	_print_in_order_traversal       ; -- Begin function print_in_order_traversal
	.p2align	2
_print_in_order_traversal:              ; @print_in_order_traversal
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	stp	x20, x19, [sp, #16]             ; 16-byte Folded Spill
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_offset w19, -24
	.cfi_offset w20, -32
	mov	x19, x0
Lloh4:
	adrp	x20, l_.str.2@PAGE
Lloh5:
	add	x20, x20, l_.str.2@PAGEOFF
	cbz	x19, LBB2_2
LBB2_1:                                 ; =>This Inner Loop Header: Depth=1
	ldr	x0, [x19, #8]
	bl	_print_in_order_traversal
	ldr	w8, [x19]
	str	x8, [sp]
	mov	x0, x20
	bl	_printf
	ldr	x19, [x19, #16]
	cbnz	x19, LBB2_1
LBB2_2:
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	ldp	x20, x19, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.loh AdrpAdd	Lloh4, Lloh5
	.cfi_endproc
                                        ; -- End function
	.globl	_reference_tree_insert          ; -- Begin function reference_tree_insert
	.p2align	2
_reference_tree_insert:                 ; @reference_tree_insert
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	stp	x20, x19, [sp, #16]             ; 16-byte Folded Spill
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_offset w19, -24
	.cfi_offset w20, -32
	mov	x19, x1
	mov	x20, x0
	ldr	x8, [x20]
	cbnz	x8, LBB3_2
	b	LBB3_5
LBB3_1:                                 ;   in Loop: Header=BB3_2 Depth=1
	add	x20, x8, #8
	ldr	x8, [x20]
	cbz	x8, LBB3_5
LBB3_2:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w9, [x8]
	cmp	w9, w19
	b.gt	LBB3_1
; %bb.3:                                ;   in Loop: Header=BB3_2 Depth=1
	b.ge	LBB3_7
; %bb.4:                                ;   in Loop: Header=BB3_2 Depth=1
	add	x20, x8, #16
	ldr	x8, [x20]
	cbnz	x8, LBB3_2
LBB3_5:
	mov	w0, #24                         ; =0x18
	bl	_malloc
	str	x0, [x20]
	cbz	x0, LBB3_8
; %bb.6:
	str	w19, [x0]
	stp	xzr, xzr, [x0, #8]
LBB3_7:
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	ldp	x20, x19, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
LBB3_8:
	str	x19, [sp]
Lloh6:
	adrp	x0, l_.str.1@PAGE
Lloh7:
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_printf
	mov	w0, #1                          ; =0x1
	bl	_exit
	.loh AdrpAdd	Lloh6, Lloh7
	.cfi_endproc
                                        ; -- End function
	.globl	_tree_destroy                   ; -- Begin function tree_destroy
	.p2align	2
_tree_destroy:                          ; @tree_destroy
	.cfi_startproc
; %bb.0:
	cbz	x0, LBB4_2
; %bb.1:
	stp	x20, x19, [sp, #-32]!           ; 16-byte Folded Spill
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_offset w19, -24
	.cfi_offset w20, -32
	ldr	x8, [x0, #8]
	mov	x19, x0
	mov	x0, x8
	bl	_tree_destroy
	ldr	x0, [x19, #16]
	bl	_tree_destroy
	mov	x0, x19
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	ldp	x20, x19, [sp], #32             ; 16-byte Folded Reload
	b	_free
LBB4_2:
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"Failed to allocate space for %d\n"

l_.str.1:                               ; @.str.1
	.asciz	"Failed to allocate space for Node containing %d\n"

l_.str.2:                               ; @.str.2
	.asciz	"%d\n"

.subsections_via_symbols
