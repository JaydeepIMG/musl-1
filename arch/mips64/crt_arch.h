__asm__(
".set push\n"
".set noreorder\n"
".text \n"
".global _" START "\n"
".global " START "\n"
".global " START "_data\n"
".type   _" START ", @function\n"
".type   " START ", @function\n"
".type   " START "_data, @function\n"
"_" START ":\n"
"" START ":\n"
".align 8 \n"
"	bal 1f \n"
"	move $fp, $0 \n"
"" START "_data: \n"
"	.gpdword " START "_data \n"
"	.gpdword " START "_c \n"
".weak _DYNAMIC \n"
".hidden _DYNAMIC \n"
"	.gpdword _DYNAMIC \n"
"1:	ld $gp, 0($ra) \n"
"	dsubu $gp, $ra, $gp \n"
"	move $4, $sp \n"
"	ld $5, 16($ra) \n"
"	daddu $5, $5, $gp \n"
"	ld $25, 8($ra) \n"
"	daddu $25, $25, $gp \n"
"	and $sp, $sp, -16 \n"
"	jalr $25 \n"
"	nop \n"
".set pop \n"
);
