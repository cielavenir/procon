#include <stdio.h>
int a[20];
int main(){
	int n,x,y,i,j,r=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",a+i),r+=a[i];
	for(j=0;j<1<<n;j++){
		for(i=x=y=0;i<n;i++){
			if(j&(1<<i))x+=a[i];
			else y+=a[i];
		}
		if(x<y)x=y;
		if(r>x)r=x;
	}
	printf("%d\n",r);
	return 0;
}