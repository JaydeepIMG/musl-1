.set    noreorder

.global __cp_begin
.hidden __cp_begin
.type   __cp_begin,@function
.global __cp_end
.hidden __cp_end
.type   __cp_end,@function
.global __cp_cancel
.hidden __cp_cancel
.type   __cp_cancel,@function
.hidden __cancel
.global __syscall_cp_asm
.hidden __syscall_cp_asm
.type   __syscall_cp_asm,@function
__syscall_cp_asm:
	subu    $sp, $sp, 32
__cp_begin:
	lw      $4, 0($4)
	move    $2, $5
	bne     $4, $0, __cp_cancel
	nop
	move    $4, $6
	move    $5, $7
	lw      $6, 48($sp)
	lw      $7, 52($sp)
	lw      $8, 56($sp)
	lw      $9, 60($sp)
	lw      $10,64($sp)
	sw      $8, 16($sp)
	sw      $9, 20($sp)
	sw      $10,24($sp)
	sw      $2, 28($sp)
	lw      $2, 28($sp)
	syscall
__cp_end:
	addu    $sp, $sp, 32
	beq     $7, $0, 1f
	nop
	subu    $2, $0, $2
1:	jr      $ra
	nop

__cp_cancel:
	move    $2, $ra

#if __mips_isa_rev < 6
#ifdef __mips_micromips
	addu    $sp, $sp, 32
	.align  2
	bal32   1f
	nop32
#else
	bal     1f
	addu    $sp, $sp, 32
#endif
#else
#ifdef __mips_micromips
	addu    $sp, $sp, 32
	.align  2
	balc32  1f
#else
	addu    $sp, $sp, 32
	balc    1f
#endif
#endif
	.gpword .
	.gpword __cancel
#ifdef __mips_micromips
1:	ins     $ra, $0, 0, 1
	lw      $3, ($ra)
	subu    $3, $ra, $3
	lw      $25, 4($ra)
	addu    $25, $25, $3
	ori     $25, $25, 1
#else
1:	lw      $3, ($ra)
	subu    $3, $ra, $3
	lw      $25, 4($ra)
	addu    $25, $25, $3
#endif
	move    $ra, $2
	jr      $25

	nop
