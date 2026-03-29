#include <stdio.h>

void func1(void)
{
    int a,b,c;

    a=98;
    b=972;
    c=a+b;

    printf("a=%d,b = %d,c= %d\n",a,b,c);
}

void func2(void)
{
    int a,b,c;

    printf("a=%d,b = %d,c= %d\n",a,b,c);    
}

int main(void)
{
    int a;

    func1();
    func2();

    return (0);
}

/*

when the variable are automatically de-allocated from th stck ,they are not completely "destroyed".
Their values are still in the memory , and this space will potentially be used by other functions.

This is why it is important to initialie your variables when you write your code, because otherwisw , they will take
whatever value there is on the stack at the moment when the program is running.

saif@saif-Inspiron-5547:~/programmer/C_Programming_Instances /Debugging_in_c$ gcc virtual_memory_demo.c && ./a.out 
a=98,b = 972,c= 1070
a=98,b = 972,c= 1070
saif@saif-Inspiron-5547:~/programmer/C_Programming_Instances /Debugging_in_c$ objdump -d -j .text -M intel
a.out:     file format elf64-x86-64


Disassembly of section .text:

0000000000400502 <func1>:
  400502:	55                   	push   rbp
  400503:	48 89 e5             	mov    rbp,rsp
  400506:	48 83 ec 10          	sub    rsp,0x10
  40050a:	c7 45 f4 62 00 00 00 	mov    DWORD PTR [rbp-0xc],0x62
  400511:	c7 45 f8 cc 03 00 00 	mov    DWORD PTR [rbp-0x8],0x3cc
  400518:	8b 55 f4             	mov    edx,DWORD PTR [rbp-0xc]
  40051b:	8b 45 f8             	mov    eax,DWORD PTR [rbp-0x8]
  40051e:	01 d0                	add    eax,edx
  400520:	89 45 fc             	mov    DWORD PTR [rbp-0x4],eax
  400523:	8b 4d fc             	mov    ecx,DWORD PTR [rbp-0x4]
  400526:	8b 55 f8             	mov    edx,DWORD PTR [rbp-0x8]
  400529:	8b 45 f4             	mov    eax,DWORD PTR [rbp-0xc]
  40052c:	89 c6                	mov    esi,eax
  40052e:	bf 04 06 40 00       	mov    edi,0x400604
  400533:	b8 00 00 00 00       	mov    eax,0x0
  400538:	e8 c3 fe ff ff       	call   400400 <printf@plt>
  40053d:	90                   	nop
  40053e:	c9                   	leave  
  40053f:	c3                   	ret    

0000000000400540 <func2>:
  400540:	55                   	push   rbp
  400541:	48 89 e5             	mov    rbp,rsp
  400544:	48 83 ec 10          	sub    rsp,0x10
  400548:	8b 4d fc             	mov    ecx,DWORD PTR [rbp-0x4]
  40054b:	8b 55 f8             	mov    edx,DWORD PTR [rbp-0x8]
  40054e:	8b 45 f4             	mov    eax,DWORD PTR [rbp-0xc]
  400551:	89 c6                	mov    esi,eax
  400553:	bf 04 06 40 00       	mov    edi,0x400604
  400558:	b8 00 00 00 00       	mov    eax,0x0
  40055d:	e8 9e fe ff ff       	call   400400 <printf@plt>
  400562:	90                   	nop
  400563:	c9                   	leave  
  400564:	c3                   	ret    

0000000000400565 <main>:
  400565:	55                   	push   rbp
  400566:	48 89 e5             	mov    rbp,rsp
  400569:	e8 94 ff ff ff       	call   400502 <func1>
  40056e:	e8 cd ff ff ff       	call   400540 <func2>
  400573:	b8 00 00 00 00       	mov    eax,0x0
  400578:	5d                   	pop    rbp
  400579:	c3                   	ret    
  40057a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]

for deeper understanding follow the blog
https://blog.holbertonschool.com/hack-virtual-memory-stack-registers-assembly-code/ 
*/
