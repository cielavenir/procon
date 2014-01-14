#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define hi(n) ((n)>>16)
#define lo(n) ((n)&0xffff)

char a[51][51],s[51],d[301];
int l;

int alignment(char *x, char *y){
	int i,j;
	for(i=1;i<=l;i++){a[i][0]=a[i-1][0]-1;}
	for(j=1;j<=l;j++){a[0][j]=a[0][j-1]-1;}
	for(i=1;i<=l;i++){
		for(j=1;j<=l;j++){
			a[i][j]=max(x[i-1]==y[j-1]?a[i-1][j-1]:(a[i-1][j-1]-1),max(a[i-1][j]-1,a[i][j-1]-1));
		}
	}
	return -a[l][l];
}
//int alignment(char *x, char *y){
//	int m=0,j=0;
//	for(;j<l;j++)m+=x[j]!=y[j];
//	return m;
//}
struct Less{
	bool operator()(const int &a, const int &b){
		return hi(a)!=hi(b) ? hi(a)<hi(b) : memcmp(d+lo(a),d+lo(b),l)<0;
	}
};
int v[280];
int main(){
	int M,m,L,i,j,n;
	for(;~scanf("%s%d%s",s,&M,d);){
		l=strlen(s);
		L=strlen(d);
		for(n=i=0;i<=L-l;i++){
			if((m=alignment(s,d+i))<=M)v[n++]=m<<16|i;
		}
		if(!n){
			puts("No match");
		}else{
			sort(v,v+n,Less());
			for(i=0;i<n;i++){
				for(j=0;j<l;j++)putchar(d[lo(v[i])+j]);
				putchar(i<n-1?' ':'\n');
			}
		}
	}
}