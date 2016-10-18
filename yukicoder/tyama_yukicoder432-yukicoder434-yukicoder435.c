#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int I[]={-1,1,5,-1,7,2,-1,4,8};
char Fk[10000001];
int Fz[10000001];
void z(int n,int *n_,int *r_){
	int r=0;
	for(;n%3==0;n/=3)r++;
	*n_=n,*r_=r;
}
int comb(int n,int k){
	char k0=Fk[n],k1=Fk[k],k2=Fk[n-k];
	int z0=Fz[n],z1=Fz[k],z2=Fz[n-k];
	int z=z0-z1-z2,r=(int)k0*I[k1]*I[k2]%9;
	return z==0 ? r : z==1 ? r*3%9 : 0;
}
int main(){
	int i;
	Fk[0]=1,Fz[0]=0;
	for(i=1;i<=10000000;i++){
		char k0=Fk[i-1];
		int z0=Fz[i-1];
		int k1,z1;
		z(i,&k1,&z1);
		Fk[i]=k0*k1%9;
		Fz[i]=z0+z1;
	}
	int T,r;
	for(scanf("%d",&T),getchar();T--;){
		bool f=true;
		r=0;
#if 0
		int n,x,a,b,m;
		scanf("%d%d%d%d%d",&n,&x,&a,&b,&m);
		for(i=0;i<n;i++){
			int c=x%10;
			r=(r+c*comb(n-1,i))%9;
			if(c)f=false;
			x=((x^a)+b)%m;
		}
#else
		char s[100001];
		scanf(" %s",s);
		int n=strlen(s);
		for(i=0;i<n;i++){
			r=(r+(s[i]-48)*comb(n-1,i))%9;
			if(s[i]!=48)f=false;
		}
#endif
		printf("%d\n",r!=0||f ? r : 9);
	}
}
