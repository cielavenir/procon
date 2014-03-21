#include <stdio.h>

int func(int n);

int main(void)
{
	int n;
	
	scanf("%d", &n);
	
	printf("%d\n", func(n));
	
	return (0);
}

int func(int n)
{
	if (n == 1){
		return (1);
	}
	
	return (n+func(n-1));
}