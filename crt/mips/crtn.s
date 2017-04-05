.set noreorder

.section .init
	lw $gp,24($sp)
	lw $ra,28($sp)
	addu $sp,$sp,32
	j $ra
	nop

.section .fini
	lw $gp,24($sp)
	lw $ra,28($sp)
	addu $sp,$sp,32
	j $ra
	nop
