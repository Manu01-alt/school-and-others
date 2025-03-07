	.file	"TERNE_PITAGORICHE-Gizzi.c"
	.text
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 8
.LC0:
	.ascii "Inserisci il numero di terne pitagoriche da generare: \0"
.LC1:
	.ascii "%d\0"
	.align 8
.LC2:
	.ascii "Le prime %d terne pitagoriche sono:\12\0"
.LC3:
	.ascii "%d %d %d\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	call	__main
	movl	$1, -4(%rbp)
	movl	$0, -16(%rbp)
	leaq	.LC0(%rip), %rcx
	call	printf
	leaq	-20(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rcx
	call	scanf
	movl	-20(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC2(%rip), %rcx
	call	printf
	jmp	.L2
.L8:
	movl	-4(%rbp), %eax
	movl	%eax, -8(%rbp)
	jmp	.L3
.L7:
	movl	-8(%rbp), %eax
	movl	%eax, -12(%rbp)
	jmp	.L4
.L6:
	movl	-4(%rbp), %eax
	imull	-4(%rbp), %eax
	movl	%eax, %edx
	movl	-8(%rbp), %eax
	imull	-8(%rbp), %eax
	addl	%eax, %edx
	movl	-12(%rbp), %eax
	imull	-12(%rbp), %eax
	cmpl	%eax, %edx
	jne	.L5
	movl	-12(%rbp), %ecx
	movl	-8(%rbp), %edx
	movl	-4(%rbp), %eax
	movl	%ecx, %r9d
	movl	%edx, %r8d
	movl	%eax, %edx
	leaq	.LC3(%rip), %rcx
	call	printf
	addl	$1, -16(%rbp)
.L5:
	addl	$1, -12(%rbp)
.L4:
	movl	-8(%rbp), %eax
	addl	%eax, %eax
	cmpl	%eax, -12(%rbp)
	jle	.L6
	addl	$1, -8(%rbp)
.L3:
	movl	-4(%rbp), %eax
	addl	%eax, %eax
	cmpl	%eax, -8(%rbp)
	jle	.L7
	addl	$1, -4(%rbp)
.L2:
	movl	-20(%rbp), %eax
	cmpl	%eax, -16(%rbp)
	jl	.L8
	movl	$0, %eax
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	scanf;	.scl	2;	.type	32;	.endef
