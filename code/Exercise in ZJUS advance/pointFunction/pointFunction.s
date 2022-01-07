	.file	"pointFunction.c"
	.text
	.section .rdata,"dr"
.LC0:
	.ascii "in f(), %d\12\0"
	.text
	.globl	f
	.def	f;	.scl	2;	.type	32;	.endef
	.seh_proc	f
f:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	16(%rbp), %edx
	leaq	.LC0(%rip), %rcx
	call	printf
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC1:
	.ascii "in g(), %d\12\0"
	.text
	.globl	g
	.def	g;	.scl	2;	.type	32;	.endef
	.seh_proc	g
g:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	16(%rbp), %edx
	leaq	.LC1(%rip), %rcx
	call	printf
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC2:
	.ascii "in h(), %d\12\0"
	.text
	.globl	h
	.def	h;	.scl	2;	.type	32;	.endef
	.seh_proc	h
h:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	16(%rbp), %edx
	leaq	.LC2(%rip), %rcx
	call	printf
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	plus
	.def	plus;	.scl	2;	.type	32;	.endef
	.seh_proc	plus
plus:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	16(%rbp), %edx
	movl	24(%rbp), %eax
	addl	%edx, %eax
	popq	%rbp
	ret
	.seh_endproc
	.globl	minus
	.def	minus;	.scl	2;	.type	32;	.endef
	.seh_proc	minus
minus:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	16(%rbp), %eax
	subl	24(%rbp), %eax
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC3:
	.ascii "%d\12\0"
	.text
	.globl	cal
	.def	cal;	.scl	2;	.type	32;	.endef
	.seh_proc	cal
cal:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movl	$3, %edx
	movl	$2, %ecx
	call	*%rax
	movl	%eax, %edx
	leaq	.LC3(%rip), %rcx
	call	printf
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC4:
	.ascii "&i:\11%p\12\0"
.LC5:
	.ascii "p:\11%p\12\0"
.LC6:
	.ascii "&a:\11%p\12\0"
.LC7:
	.ascii "&a[0]:\11%p\12\0"
.LC8:
	.ascii "&a[1]:\11%p\12\0"
.LC9:
	.ascii "pint:\11%p\12\0"
.LC10:
	.ascii "main:\11%p\12\0"
.LC11:
	.ascii "f:\11%p\12\0"
.LC12:
	.ascii "pf:\11%p\12\0"
.LC13:
	.ascii "%d\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$96, %rsp
	.seh_stackalloc	96
	.seh_endprologue
	call	__main
	movl	$0, -28(%rbp)
	leaq	-28(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	$20, (%rax)
	movl	$1, -36(%rbp)
	movl	$2, -32(%rbp)
	leaq	f(%rip), %rax
	movq	%rax, -16(%rbp)
	movl	$4, %ecx
	call	malloc
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movl	$100, (%rax)
	leaq	-28(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC4(%rip), %rcx
	call	printf
	movq	-8(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC5(%rip), %rcx
	call	printf
	leaq	-36(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC6(%rip), %rcx
	call	printf
	leaq	-36(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC7(%rip), %rcx
	call	printf
	leaq	-36(%rbp), %rax
	addq	$4, %rax
	movq	%rax, %rdx
	leaq	.LC8(%rip), %rcx
	call	printf
	movq	-24(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC9(%rip), %rcx
	call	printf
	leaq	main(%rip), %rdx
	leaq	.LC10(%rip), %rcx
	call	printf
	leaq	f(%rip), %rdx
	leaq	.LC11(%rip), %rcx
	call	printf
	movq	-16(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC12(%rip), %rcx
	call	printf
	movl	$20, %ecx
	call	f
	movq	-16(%rbp), %rax
	movl	$10, %ecx
	call	*%rax
	leaq	f(%rip), %rax
	movq	%rax, -64(%rbp)
	leaq	g(%rip), %rax
	movq	%rax, -56(%rbp)
	leaq	h(%rip), %rax
	movq	%rax, -48(%rbp)
	leaq	-28(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC13(%rip), %rcx
	call	scanf
	movl	-28(%rbp), %eax
	testl	%eax, %eax
	js	.L10
	movl	-28(%rbp), %eax
	cmpl	$2, %eax
	ja	.L10
	movl	-28(%rbp), %eax
	cltq
	movq	-64(%rbp,%rax,8), %rax
	movl	-28(%rbp), %edx
	movl	%edx, %ecx
	call	*%rax
.L10:
	movq	-24(%rbp), %rax
	movq	%rax, %rcx
	call	free
	leaq	plus(%rip), %rcx
	call	cal
	leaq	minus(%rip), %rcx
	call	cal
	movl	$0, %eax
	addq	$96, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	malloc;	.scl	2;	.type	32;	.endef
	.def	scanf;	.scl	2;	.type	32;	.endef
	.def	free;	.scl	2;	.type	32;	.endef
