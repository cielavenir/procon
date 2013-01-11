#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <map>
using namespace std;
#define PAD 0
#define DEPTH 7
map<int,int>m;
int largest=0;
char s[99];
long long a,b,H;
int t=0;
void calc(int d){
	long long h=0;
	int i=0;
	for(;i<d;i++)h=(h*a+(s[i]-'a'+1))%b;
	if(h==H){
		assert(d==strlen(s));
		puts(s),t++;
		if(t==100)exit(0);
	}
}
void D(int d){
	for(s[d]='t';s[d]<='z';s[d]++){
		calc(d+1);
		if(d+1<DEPTH+PAD)D(d+1);
	}
	s[d]=0;
}
void calc2(int d){
	long long h=0;
	int i=0;
	for(;i<d;i++)h=(h*a+(s[i]-'a'+1))%b;
	m[h]++;
	if(largest<m[h])largest=m[h],H=h;
}
void D2(int d){
	for(s[d]='t';s[d]<='z';s[d]++){
		calc2(d+1);
		if(d+1<DEPTH+PAD)D2(d+1);
	}
	s[d]=0;
}
int main(){
	int i;
	scanf("%lld%lld",&a,&b);
	strcpy(s,"");
	assert(PAD==strlen(s));
	D2(PAD);
	D(PAD);
	exit(0);
}