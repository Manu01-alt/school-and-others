	.file	"main.c"
	.text
	.globl	indice
	.data
	.align 4
indice:
	.long	1
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 8
.LC0:
	.ascii "\12--------------------------------\12Scegliere un opzione:\12A - Aggiungi domanda\12S - Somministra questionario\12C - Cancella domanda\12X - Termina.\12>\0"
.LC1:
	.ascii "%c\0"
.LC2:
	.ascii "\12Bye!!\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	movl	$1, -4(%rbp)
	jmp	.L2
.L9:
	leaq	.LC0(%rip), %rcx
	call	printf
	movl	$0, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rax, %rcx
	call	fflush
	leaq	-5(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rcx
	call	scanf
	movzbl	-5(%rbp), %eax
	movsbl	%al, %eax
	movl	%eax, %ecx
	movq	__imp_toupper(%rip), %rax
	call	*%rax
	cmpl	$67, %eax
	je	.L3
	cmpl	$67, %eax
	jg	.L4
	cmpl	$65, %eax
	je	.L5
	jmp	.L2
.L4:
	cmpl	$83, %eax
	je	.L7
	cmpl	$88, %eax
	je	.L8
	jmp	.L2
.L5:
	call	aggiungi_domanda
	jmp	.L2
.L7:
	call	somministra_questionario
	jmp	.L2
.L3:
	call	cancella_domanda
	jmp	.L2
.L8:
	leaq	.LC2(%rip), %rcx
	call	puts
	movl	$0, -4(%rbp)
	nop
.L2:
	cmpl	$0, -4(%rbp)
	jne	.L9
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	fflush;	.scl	2;	.type	32;	.endef
	.def	scanf;	.scl	2;	.type	32;	.endef
	.def	aggiungi_domanda;	.scl	2;	.type	32;	.endef
	.def	somministra_questionario;	.scl	2;	.type	32;	.endef
	.def	cancella_domanda;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef
