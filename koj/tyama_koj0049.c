#include <stdio.h>

void func(int *a, int *b);

int main(void)
{
	int a, b;
	
	scanf("%d %d", &a, &b);
	
	func(&a,&b);
	
	printf("%d %d\n", a, b);
	
	return (0);
}

void func(int *a, int *b)
{
	int x=*a;*a=*b;*b=x;
}