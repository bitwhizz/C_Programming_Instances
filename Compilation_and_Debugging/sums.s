	.file	"sum.c"
	.section	.rodata
.LC0:
	.string	"compiled sum:%d\n"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$32, %esp
	movl	$5, 28(%esp)
	movl	$7, 24(%esp)
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	leal	(%edx,%eax), %eax
	movl	%eax, 20(%esp)
	movl	$.LC0, %eax
	movl	20(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$0, %eax
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.4.3-4ubuntu5) 4.4.3"
	.section	.note.GNU-stack,"",@progbits
