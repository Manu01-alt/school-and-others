	.file	"main.c"
	.text
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "a\0"
.LC1:
	.ascii "ARP_table.txt\0"
	.align 8
.LC2:
	.ascii "Inserire indirizzo IP o digitare 'fine': \0"
.LC3:
	.ascii "%s\0"
.LC4:
	.ascii "fine\0"
.LC5:
	.ascii "Inserire indirizzo MAC: \0"
.LC6:
	.ascii "IP = %s MAC = %s\12\0"
	.align 8
.LC7:
	.ascii "IP salvati sul file di testo: \0"
.LC8:
	.ascii "r\0"
.LC9:
	.ascii "\12\12TABELLA:\0"
.LC10:
	.ascii "File chiuso\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$144, %rsp
	.seh_stackalloc	144
	.seh_endprologue
	call	__main
	leaq	.LC0(%rip), %rdx
	leaq	.LC1(%rip), %rcx
	call	fopen
	movq	%rax, -16(%rbp)
	movl	$16, %edx
	movl	$1, %ecx
	call	calloc
	movq	%rax, -24(%rbp)
	movl	$18, %edx
	movl	$1, %ecx
	call	calloc
	movq	%rax, -32(%rbp)
	movl	$1, -4(%rbp)
.L4:
	leaq	.LC2(%rip), %rcx
	call	printf
	movq	-24(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC3(%rip), %rcx
	call	scanf
	movq	-24(%rbp), %rax
	leaq	.LC4(%rip), %rdx
	movq	%rax, %rcx
	call	strcmp
	testl	%eax, %eax
	je	.L2
	leaq	.LC5(%rip), %rcx
	call	printf
	movq	-32(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC3(%rip), %rcx
	call	scanf
	movq	-32(%rbp), %rcx
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rax
	movq	%rcx, %r9
	movq	%rdx, %r8
	leaq	.LC6(%rip), %rdx
	movq	%rax, %rcx
	call	fprintf
	jmp	.L3
.L2:
	movl	$0, -4(%rbp)
.L3:
	cmpl	$1, -4(%rbp)
	je	.L4
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	leaq	.LC7(%rip), %rcx
	call	puts
	leaq	.LC8(%rip), %rdx
	leaq	.LC1(%rip), %rcx
	call	fopen
	movq	%rax, -40(%rbp)
	movq	$50, -48(%rbp)
	leaq	.LC9(%rip), %rcx
	call	puts
	jmp	.L5
.L6:
	leaq	-112(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC3(%rip), %rcx
	call	printf
.L5:
	movq	-48(%rbp), %rax
	movl	%eax, %ecx
	movq	-40(%rbp), %rdx
	leaq	-112(%rbp), %rax
	movq	%rdx, %r8
	movl	%ecx, %edx
	movq	%rax, %rcx
	call	fgets
	testq	%rax, %rax
	jne	.L6
	movq	-40(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	leaq	.LC10(%rip), %rcx
	call	printf
	movl	$0, %eax
	addq	$144, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	fopen;	.scl	2;	.type	32;	.endef
	.def	calloc;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	scanf;	.scl	2;	.type	32;	.endef
	.def	strcmp;	.scl	2;	.type	32;	.endef
	.def	fprintf;	.scl	2;	.type	32;	.endef
	.def	fclose;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	fgets;	.scl	2;	.type	32;	.endef
