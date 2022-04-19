#include <stdio.h>
#include <stdlib.h>

int main() {
	int a;
	long b;
	int c[5];
	char d;
	char e[5];
	int *f;

	a = 1;
	b = 1234567890;
	c[0] = 10;
	d = 'A';
	e[0] = 'H'; e[1]= 'E'; e[2] = 'L'; e[3] = 'L'; e[4] = 'O'; e[5] = '\0';
	f = &a;
	
	printf("a = %d, &a = %p\n",a,&a);
	printf("b = %ld, &b = %p\n",b,&b);
	printf("c[0] = %d, &c[0] = %p\n",c[0],&c[0]);
	printf("d = %d, &d = %p\n",d,&d);
	printf("e = %s, &e = %p\n",e,&e);
	printf("&e[0] = %p\n",&e[0]);
	printf("&e[1] = %p\n",&e[1]);
	printf("f = %p, &f = %p\n",f,&f);
}
