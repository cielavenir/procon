#include <string>
#include <set>
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
	return chk(s)+'0'==s[M];
}
int main(){
	set<string>se;
	for(int i=0;i<10;i++)for(int j=0;j<10;j++)scanf("%d",m[i]+j);
	for(int i=0;i<10000;i++){
		sprintf(s0,"%04d",i);
		string s=s0;
		s+=chk(s)+'0';
		se.insert(s);
	}
	printf("%d\n",count_if(se.begin(),se.end(),[&](string s)->bool{
		for(int i=0;i<M;i++)if(s[i]!=s[i+1]){
			swap(s[i],s[i+1]);
			if(correct(s))return true;
			swap(s[i],s[i+1]);
		}
		for(int i=0;i<=M;i++)for(int j='0';j<='9';j++)if(s[i]!=j){
			string t=s;
			t[i]=j;
			if(correct(t))return true;
		}
		return false;
	}));
}
