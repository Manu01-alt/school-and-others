	.file	"MyLib.c"
	.text
	.comm	indice, 4, 2
	.section .rdata,"dr"
.LC0:
	.ascii "a\0"
.LC1:
	.ascii "questionario.txt\0"
.LC2:
	.ascii "\12Insert question:\0"
.LC3:
	.ascii "%d. %s\0"
.LC4:
	.ascii "Insert the 4 options:\0"
.LC5:
	.ascii "%c:%s\0"
.LC6:
	.ascii "Insert the correct option\0"
.LC7:
	.ascii "%c\0"
.LC8:
	.ascii "%c\12\0"
	.text
	.globl	aggiungi_domanda
	.def	aggiungi_domanda;	.scl	2;	.type	32;	.endef
	.seh_proc	aggiungi_domanda
aggiungi_domanda:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$80, %rsp
	.seh_stackalloc	80
	.seh_endprologue
	leaq	.LC0(%rip), %rdx
	leaq	.LC1(%rip), %rcx
	call	fopen
	movq	%rax, -16(%rbp)
	movl	$250, %edx
	movl	$1, %ecx
	call	calloc
	movq	%rax, -24(%rbp)
	movl	$250, %edx
	movl	$1, %ecx
	call	calloc
	movq	%rax, -32(%rbp)
	movb	$65, -5(%rbp)
	leaq	.LC2(%rip), %rcx
	call	printf
	nop
.L2:
	call	getchar
	movl	%eax, -36(%rbp)
	cmpl	$10, -36(%rbp)
	jne	.L2
	movl	$0, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rax, %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %r8
	movl	$250, %edx
	movq	%rax, %rcx
	call	fgets
	leaq	indice(%rip), %rax
	movl	(%rax), %edx
	movq	-24(%rbp), %rcx
	movq	-16(%rbp), %rax
	movq	%rcx, %r9
	movl	%edx, %r8d
	leaq	.LC3(%rip), %rdx
	movq	%rax, %rcx
	call	fprintf
	leaq	.LC4(%rip), %rcx
	call	puts
	movl	$0, -4(%rbp)
	jmp	.L3
.L4:
	movl	$0, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rax, %rdx
	movq	-32(%rbp), %rax
	movq	%rdx, %r8
	movl	$250, %edx
	movq	%rax, %rcx
	call	fgets
	movsbl	-5(%rbp), %edx
	movq	-32(%rbp), %rcx
	movq	-16(%rbp), %rax
	movq	%rcx, %r9
	movl	%edx, %r8d
	leaq	.LC5(%rip), %rdx
	movq	%rax, %rcx
	call	fprintf
	movzbl	-5(%rbp), %eax
	addl	$1, %eax
	movb	%al, -5(%rbp)
	addl	$1, -4(%rbp)
.L3:
	cmpl	$3, -4(%rbp)
	jle	.L4
	leaq	.LC6(%rip), %rcx
	call	puts
	leaq	-37(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC7(%rip), %rcx
	call	scanf
	movzbl	-37(%rbp), %eax
	movsbl	%al, %eax
	movl	%eax, %ecx
	movq	__imp_toupper(%rip), %rax
	call	*%rax
	movl	%eax, %edx
	movq	-16(%rbp), %rax
	movl	%edx, %r8d
	leaq	.LC8(%rip), %rdx
	movq	%rax, %rcx
	call	fprintf
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	leaq	indice(%rip), %rax
	movl	(%rax), %eax
	leal	1(%rax), %edx
	leaq	indice(%rip), %rax
	movl	%edx, (%rax)
	movq	-24(%rbp), %rax
	movq	%rax, %rcx
	call	free
	movq	-32(%rbp), %rax
	movq	%rax, %rcx
	call	free
	nop
	addq	$80, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC9:
	.ascii "r\0"
.LC10:
	.ascii "%s\0"
.LC11:
	.ascii "Insert the correct answer:\0"
.LC12:
	.ascii "\12Wrong answer.\0"
.LC13:
	.ascii "\12Correct answer.\0"
.LC14:
	.ascii "\12Score: %d\12\12\0"
	.text
	.globl	somministra_questionario
	.def	somministra_questionario;	.scl	2;	.type	32;	.endef
	.seh_proc	somministra_questionario
somministra_questionario:
	pushq	%rbp
	.seh_pushreg	%rbp
	subq	$320, %rsp
	.seh_stackalloc	320
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	leaq	.LC9(%rip), %rdx
	leaq	.LC1(%rip), %rcx
	call	fopen
	movq	%rax, 176(%rbp)
	movq	$250, 168(%rbp)
	movl	$0, 188(%rbp)
	jmp	.L6
.L10:
	movl	$0, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rax, %rcx
	call	fflush
	movl	$10, %ecx
	call	putchar
	movl	$0, 184(%rbp)
	jmp	.L7
.L8:
	leaq	-96(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC10(%rip), %rcx
	call	printf
	movq	168(%rbp), %rax
	movl	%eax, %ecx
	movq	176(%rbp), %rdx
	leaq	-96(%rbp), %rax
	movq	%rdx, %r8
	movl	%ecx, %edx
	movq	%rax, %rcx
	call	fgets
	addl	$1, 184(%rbp)
.L7:
	cmpl	$4, 184(%rbp)
	jle	.L8
	movzbl	-96(%rbp), %eax
	movb	%al, 167(%rbp)
	leaq	.LC11(%rip), %rcx
	call	printf
	leaq	166(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC7(%rip), %rcx
	call	scanf
	movzbl	166(%rbp), %eax
	movsbl	%al, %eax
	movl	%eax, %ecx
	movq	__imp_toupper(%rip), %rax
	call	*%rax
	movl	%eax, %edx
	movsbl	167(%rbp), %eax
	cmpl	%eax, %edx
	je	.L9
	leaq	.LC12(%rip), %rcx
	call	puts
	jmp	.L6
.L9:
	leaq	.LC13(%rip), %rcx
	call	puts
	addl	$1, 188(%rbp)
	movl	188(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC14(%rip), %rcx
	call	printf
.L6:
	movq	168(%rbp), %rax
	movl	%eax, %ecx
	movq	176(%rbp), %rdx
	leaq	-96(%rbp), %rax
	movq	%rdx, %r8
	movl	%ecx, %edx
	movq	%rax, %rcx
	call	fgets
	testq	%rax, %rax
	jne	.L10
	movq	176(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	nop
	addq	$320, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC15:
	.ascii "%s...\12\0"
	.align 8
.LC16:
	.ascii "\12Choose which question to delete: \0"
.LC17:
	.ascii "%u\0"
.LC18:
	.ascii "w\0"
.LC19:
	.ascii "questionario_appoggio.txt\0"
.LC20:
	.ascii "%u %[^\12]\0"
.LC21:
	.ascii "%u%s\12\0"
	.text
	.globl	cancella_domanda
	.def	cancella_domanda;	.scl	2;	.type	32;	.endef
	.seh_proc	cancella_domanda
cancella_domanda:
	pushq	%rbp
	.seh_pushreg	%rbp
	subq	$608, %rsp
	.seh_stackalloc	608
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	leaq	.LC9(%rip), %rdx
	leaq	.LC1(%rip), %rcx
	call	fopen
	movq	%rax, 464(%rbp)
	jmp	.L12
.L17:
	leaq	176(%rbp), %rax
	movq	%rax, %rcx
	call	strlen
	movq	%rax, 456(%rbp)
	cmpq	$50, 456(%rbp)
	jbe	.L13
	movb	$0, 226(%rbp)
	leaq	176(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC15(%rip), %rcx
	call	printf
	jmp	.L14
.L13:
	leaq	176(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC10(%rip), %rcx
	call	printf
.L14:
	movl	$0, 476(%rbp)
	jmp	.L15
.L16:
	movq	464(%rbp), %rdx
	leaq	176(%rbp), %rax
	movq	%rdx, %r8
	movl	$250, %edx
	movq	%rax, %rcx
	call	fgets
	addl	$1, 476(%rbp)
.L15:
	cmpl	$4, 476(%rbp)
	jle	.L16
.L12:
	movq	464(%rbp), %rdx
	leaq	176(%rbp), %rax
	movq	%rdx, %r8
	movl	$250, %edx
	movq	%rax, %rcx
	call	fgets
	testq	%rax, %rax
	jne	.L17
	movq	464(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	movl	$0, 172(%rbp)
	leaq	.LC16(%rip), %rcx
	call	printf
	leaq	172(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC17(%rip), %rcx
	call	scanf
	leaq	.LC9(%rip), %rdx
	leaq	.LC1(%rip), %rcx
	call	fopen
	movq	%rax, 448(%rbp)
	leaq	.LC18(%rip), %rdx
	leaq	.LC19(%rip), %rcx
	call	fopen
	movq	%rax, 440(%rbp)
	movl	$0, 472(%rbp)
	jmp	.L18
.L28:
	movl	$0, 168(%rbp)
	leaq	-96(%rbp), %rcx
	leaq	168(%rbp), %rdx
	leaq	176(%rbp), %rax
	movq	%rcx, %r9
	movq	%rdx, %r8
	leaq	.LC20(%rip), %rdx
	movq	%rax, %rcx
	call	sscanf
	movl	168(%rbp), %edx
	movl	172(%rbp), %eax
	cmpl	%eax, %edx
	je	.L19
	cmpl	$0, 472(%rbp)
	jne	.L20
	movq	440(%rbp), %rdx
	leaq	176(%rbp), %rax
	movq	%rax, %rcx
	call	fputs
	jmp	.L21
.L20:
	movl	168(%rbp), %eax
	leal	-1(%rax), %ecx
	leaq	-96(%rbp), %rdx
	movq	440(%rbp), %rax
	movq	%rdx, %r9
	movl	%ecx, %r8d
	leaq	.LC21(%rip), %rdx
	movq	%rax, %rcx
	call	fprintf
.L21:
	movl	$0, 476(%rbp)
	jmp	.L22
.L24:
	movq	448(%rbp), %rdx
	leaq	176(%rbp), %rax
	movq	%rdx, %r8
	movl	$250, %edx
	movq	%rax, %rcx
	call	fgets
	testq	%rax, %rax
	je	.L23
	movq	440(%rbp), %rdx
	leaq	176(%rbp), %rax
	movq	%rax, %rcx
	call	fputs
.L23:
	addl	$1, 476(%rbp)
.L22:
	cmpl	$4, 476(%rbp)
	jle	.L24
	jmp	.L18
.L19:
	movl	$1, 472(%rbp)
	movl	$0, 476(%rbp)
	jmp	.L26
.L27:
	movq	448(%rbp), %rdx
	leaq	176(%rbp), %rax
	movq	%rdx, %r8
	movl	$250, %edx
	movq	%rax, %rcx
	call	fgets
	addl	$1, 476(%rbp)
.L26:
	cmpl	$4, 476(%rbp)
	jle	.L27
.L18:
	movq	448(%rbp), %rdx
	leaq	176(%rbp), %rax
	movq	%rdx, %r8
	movl	$250, %edx
	movq	%rax, %rcx
	call	fgets
	testq	%rax, %rax
	jne	.L28
	movq	448(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	movq	440(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	leaq	.LC1(%rip), %rcx
	call	remove
	leaq	.LC1(%rip), %rdx
	leaq	.LC19(%rip), %rcx
	call	rename
	nop
	addq	$608, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	fopen;	.scl	2;	.type	32;	.endef
	.def	calloc;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	getchar;	.scl	2;	.type	32;	.endef
	.def	fgets;	.scl	2;	.type	32;	.endef
	.def	fprintf;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	scanf;	.scl	2;	.type	32;	.endef
	.def	fclose;	.scl	2;	.type	32;	.endef
	.def	free;	.scl	2;	.type	32;	.endef
	.def	fflush;	.scl	2;	.type	32;	.endef
	.def	putchar;	.scl	2;	.type	32;	.endef
	.def	strlen;	.scl	2;	.type	32;	.endef
	.def	sscanf;	.scl	2;	.type	32;	.endef
	.def	fputs;	.scl	2;	.type	32;	.endef
	.def	remove;	.scl	2;	.type	32;	.endef
	.def	rename;	.scl	2;	.type	32;	.endef
