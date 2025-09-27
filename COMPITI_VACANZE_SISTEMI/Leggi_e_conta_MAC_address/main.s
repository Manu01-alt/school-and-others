	.file	"main.c"
	.text
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "r\0"
.LC1:
	.ascii "mac_list.txt\0"
.LC2:
	.ascii "%s\0"
	.align 8
.LC3:
	.ascii "\12sono stati stampati %d MAC address\0"
.LC4:
	.ascii "\12\12File chiuso\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$80, %rsp
	.seh_stackalloc	80
	.seh_endprologue
	call	__main
	movq	$19, -16(%rbp)
	movl	$0, -4(%rbp)
	leaq	.LC0(%rip), %rdx
	leaq	.LC1(%rip), %rcx
	call	fopen
	movq	%rax, -24(%rbp)
	jmp	.L2
.L3:
	leaq	-48(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC2(%rip), %rcx
	call	printf
	addl	$1, -4(%rbp)
.L2:
	movq	-16(%rbp), %rax
	movl	%eax, %ecx
	movq	-24(%rbp), %rdx
	leaq	-48(%rbp), %rax
	movq	%rdx, %r8
	movl	%ecx, %edx
	movq	%rax, %rcx
	call	fgets
	testq	%rax, %rax
	jne	.L3
	movq	-24(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	movl	-4(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC3(%rip), %rcx
	call	printf
	leaq	.LC4(%rip), %rcx
	call	printf
	movl	$0, %eax
	addq	$80, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	fopen;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	fgets;	.scl	2;	.type	32;	.endef
	.def	fclose;	.scl	2;	.type	32;	.endef
