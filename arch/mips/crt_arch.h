__asm__(
".set push\n"
".set noreorder\n"
".text \n"
".global _" START "\n"
".global " START "\n"
".type   _" START ", @function\n"
".type   " START ", @function\n"
"_" START ":\n"
"" START ":\n"
#if __mips_isa_rev < 6
#ifdef __mips_micromips
"	move $fp, $0 \n"
"	.align 2 \n"
"	bal32 1f \n"
"	nop32 \n"
#else
"	bal 1f \n"
"	 move $fp, $0 \n"
#endif
#else
"	move $fp, $0 \n"
"	.align 2 \n"
"	balc 1f \n"
#endif
"	.gpword . \n"
"	.gpword " START "_c \n"
".weak _DYNAMIC \n"
".hidden _DYNAMIC \n"
"	.gpword _DYNAMIC \n"

#ifdef __mips_micromips
"1:	ins $ra, $0, 0, 1 \n"
"	lw $gp, 0($ra) \n"
"	subu $gp, $ra, $gp \n"
"	move $4, $sp \n"
"	lw $5, 8($ra) \n"
"	addu $5, $5, $gp \n"
"	lw $25, 4($ra) \n"
"	addu $25, $25, $gp \n"
"	ori $25, $25, 1 \n"
"	and $sp, $sp, -8 \n"
#else
"1:	lw $gp, 0($ra) \n"
"	subu $gp, $ra, $gp \n"
"	move $4, $sp \n"
"	lw $5, 8($ra) \n"
"	addu $5, $5, $gp \n"
"	lw $25, 4($ra) \n"
"	addu $25, $25, $gp \n"
"	and $sp, $sp, -8 \n"
#endif

#if __mips_isa_rev < 6
"	jalr $25 \n"
"	 subu $sp, $sp, 16 \n"
#else
"	subu $sp, $sp, 16 \n"
"	jalrc $25 \n"
#endif
".set pop \n"
);
