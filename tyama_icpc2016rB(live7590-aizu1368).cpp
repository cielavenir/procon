#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;
const int M=4;
int m[10][10];
char s0[M+2];
int chk(const string &s){
	int d=0;
	for(int i=0;i<4;i++)d=m[d][s[i]-'0'];
	return d;
}
bool correct(const string &s){
	return m[chk(s)][s[M]-'0']==0;
}
int main(){
loop:
	for(int i=0;i<10;i++)for(int j=0;j<10;j++){
		if(scanf("%d",m[i]+j)<0)return 0;
	}
	int r=0;
	for(int i=0;i<10000;i++){
		sprintf(s0,"%04d",i);
		string s=s0;
		s+=chk(s)+'0';
		r+=[&]{
			for(int i=0;i<M;i++)if(s[i]!=s[i+1]){
				swap(s[i],s[i+1]);
				if(correct(s))return true;
				swap(s[i],s[i+1]);
			}
			for(int i=0;i<=M;i++)for(char j='0';j<='9';j++)if(s[i]!=j){
				swap(s[i],j);
				if(correct(s))return true;
				swap(s[i],j);
			}
			return false;
		}();
	}
	printf("%d\n",r);
goto loop;
}
