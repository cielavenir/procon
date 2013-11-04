#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
char x[9],y[9];
int check(int n){
	sprintf(x,"%d",n);
	strcpy(y,x);
	std::reverse(y,y+strlen(y));
	return !strcmp(x,y);
}
main(){
	int a,b,x,r,i,j,k;
	for(;~scanf("%d%d",&a,&b);printf("%d\n",r)){
		std::vector<int>v(b-a+1);
		for(r=i=0;i<=b-a;i++)v[i]=check(i+a);
		for(i=1;i<=b-a+1;i++){
			for(k=0;k<=b-a-i+1;k++){
				for(x=j=0;j<i;j++)x+=v[k+j];
				if(x%2==0)r++;
			}
		}
	}
}