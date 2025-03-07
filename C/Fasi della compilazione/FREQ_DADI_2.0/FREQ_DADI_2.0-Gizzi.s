	.file	"FREQ_DADI_2.0-Gizzi.c"
	.text
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "Inserire il numero di lanci: \0"
.LC1:
	.ascii "%d\0"
.LC2:
	.ascii "Inserire il numero di dadi: \0"
.LC3:
	.ascii "Inserire il numero di facce: \0"
.LC4:
	.ascii "\12Dado %d:\12\0"
.LC5:
	.ascii "\12Frequenze dei numeri:\0"
.LC6:
	.ascii "Numero %d: %d volte\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$104, %rsp
	.seh_stackalloc	104
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	call	__main
	movq	%rsp, %rax
	movq	%rax, %rbx
	movl	$0, %ecx
	call	time
	movl	%eax, %ecx
	call	srand
	leaq	.LC0(%rip), %rcx
	call	printf
	leaq	-80(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rcx
	call	scanf
	leaq	.LC2(%rip), %rcx
	call	printf
	leaq	-84(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rcx
	call	scanf
	leaq	.LC3(%rip), %rcx
	call	printf
	leaq	-88(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rcx
	call	scanf
	movl	-88(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	subq	$1, %rdx
	movq	%rdx, -64(%rbp)
	movslq	%eax, %rdx
	movq	%rdx, %r12
	movl	$0, %r13d
	movslq	%eax, %rdx
	movq	%rdx, %rsi
	movl	$0, %edi
	cltq
	salq	$2, %rax
	addq	$15, %rax
	shrq	$4, %rax
	salq	$4, %rax
	call	___chkstk_ms
	subq	%rax, %rsp
	leaq	32(%rsp), %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -72(%rbp)
	movl	$1, -52(%rbp)
	jmp	.L2
.L3:
	movq	-72(%rbp), %rdx
	movl	-52(%rbp), %eax
	cltq
	movl	$0, (%rdx,%rax,4)
	addl	$1, -52(%rbp)
.L2:
	movl	-88(%rbp), %eax
	cmpl	%eax, -52(%rbp)
	jle	.L3
	movl	$0, -48(%rbp)
	jmp	.L4
.L11:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %edx
	leaq	.LC4(%rip), %rcx
	call	printf
	movl	$1, -44(%rbp)
	jmp	.L5
.L6:
	movq	-72(%rbp), %rdx
	movl	-44(%rbp), %eax
	cltq
	movl	$0, (%rdx,%rax,4)
	addl	$1, -44(%rbp)
.L5:
	movl	-88(%rbp), %eax
	cmpl	%eax, -44(%rbp)
	jle	.L6
	movl	$0, -40(%rbp)
	jmp	.L7
.L8:
	call	rand
	movl	-88(%rbp), %ecx
	cltd
	idivl	%ecx
	movl	%edx, %eax
	addl	$1, %eax
	movl	%eax, -76(%rbp)
	movq	-72(%rbp), %rdx
	movl	-76(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %eax
	leal	1(%rax), %ecx
	movq	-72(%rbp), %rdx
	movl	-76(%rbp), %eax
	cltq
	movl	%ecx, (%rdx,%rax,4)
	addl	$1, -40(%rbp)
.L7:
	movl	-80(%rbp), %eax
	cmpl	%eax, -40(%rbp)
	jl	.L8
	leaq	.LC5(%rip), %rcx
	call	puts
	movl	$1, -36(%rbp)
	jmp	.L9
.L10:
	movq	-72(%rbp), %rdx
	movl	-36(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %edx
	movl	-36(%rbp), %eax
	movl	%edx, %r8d
	movl	%eax, %edx
	leaq	.LC6(%rip), %rcx
	call	printf
	addl	$1, -36(%rbp)
.L9:
	movl	-88(%rbp), %eax
	cmpl	%eax, -36(%rbp)
	jle	.L10
	addl	$1, -48(%rbp)
.L4:
	movl	-84(%rbp), %eax
	cmpl	%eax, -48(%rbp)
	jl	.L11
	movl	$0, %eax
	movq	%rbx, %rsp
	leaq	-24(%rbp), %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%r12
	popq	%r13
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	time;	.scl	2;	.type	32;	.endef
	.def	srand;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	scanf;	.scl	2;	.type	32;	.endef
	.def	rand;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef
