#include <stdio.h>
#include <stdbool.h>
#define M 4

#ifdef __cplusplus
#include <algorithm>
using namespace std;
#else
#define swap(a,b) a^=b,b^=a,a^=b
#endif

int m[10][10];
char s[M+2];
int chk(const char *s){
	int d=0,i=0;
	for(;i<4;i++)d=m[d][s[i]-'0'];
	return d;
}
bool correct(const char *s){
	return m[chk(s)][s[M]-'0']==0;
}
bool solve(char *s){
	int i;char j;
	for(i=0;i<M;i++)if(s[i]!=s[i+1]){
		swap(s[i],s[i+1]);
		if(correct(s))return true;
		swap(s[i],s[i+1]);
	}
	for(i=0;i<=M;i++)for(j='0';j<='9';j++)if(s[i]!=j){
		swap(s[i],j);
		if(correct(s))return true;
		swap(s[i],j);
	}
	return false;
}
int main(){
	int r,i,j;
loop:
	for(r=i=0;i<10;i++)for(j=0;j<10;j++){
		if(scanf("%d",m[i]+j)<0)return 0;
	}
	for(i=0;i<10000;i++){
		sprintf(s,"%04d",i);
		s[M]=chk(s)+'0';
		r+=solve(s);
	}
	printf("%d\n",r);
goto loop;
}
