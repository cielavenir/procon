#include <stdio.h>
int a[6];
int main(){ //console interface
	int x,i,s=0;
	scanf("%d",&x);x=1000-x;
	a[5]=x%1000/500,a[4]=x%500/100,a[3]=x%100/50,a[2]=x%50/10,a[1]=x%10/5,a[0]=x%5;
	for(i=5;i>=0;i--)s+=a[i];
	printf("%d\n",s);
	for(i=5;i>=0;i--)printf("%d\n",a[i]);
	return 0;
}