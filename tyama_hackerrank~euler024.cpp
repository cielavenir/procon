#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
	//string v="0123456789";
	string v="abcdefghijklm";
	int T;
	long long _o=1;for(int i=1;i<=v.size();i++)_o*=i;
	long long i=1000000,j;
	for(scanf("%d",&T);T--;){
	scanf("%lld",&i);
	i-=1;
	long long o=_o;
	string V=v,a;
	for(;V.size();){
		//j=i%o/(o=o/V.size()); ///(o=o+3>>2);
		j=i%o,o/=V.size(),j/=o;
		a+=V[j];
		V.erase(V.begin()+j);
	}
	puts(a.c_str());
	}
}