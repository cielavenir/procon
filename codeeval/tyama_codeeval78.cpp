#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int m[100][100],z[101],M;
int grid(){
	int i,j;
	for(i=0;i<M*M;i++){
		memset(z,0,sizeof(z));
		for(j=0;j<M*M;j++)if(m[i][j])z[m[i][j]]++;
		for(j=0;j<M*M;j++)if(z[m[i][j]]>1)return 0;
	}
	for(i=0;i<M*M;i++){
		memset(z,0,sizeof(z));
		for(j=0;j<M*M;j++)if(m[j][i])z[m[j][i]]++;
		for(j=0;j<M*M;j++)if(z[m[j][i]]>1)return 0;
	}
	for(i=0;i<M*M;i++){
		memset(z,0,sizeof(z));
		for(j=0;j<M*M;j++)if(m[i%M*M+j/M][i/M*M+j%M])z[m[i%M*M+j/M][i/M*M+j%M]]++;
		for(j=0;j<M*M;j++)if(z[m[i%M*M+j/M][i/M*M+j%M]]>1)return 0;
	}
	return 1;
}
int main(int argc, char **argv){
	string s;
	//ifstream fin(argv[1]);
	for(;getline(cin,s);){
		int i,j,n;
		for(i=0;i<s.length();i++)if(s[i]==';'||s[i]==',')s[i]=' ';
		istringstream ss(s);
		ss>>M;
		M=(int)sqrt(M);
		for(i=0;i<M*M;i++)for(j=0;j<M*M;j++)ss>>m[i][j];
		puts(grid()?"True":"False");
	}
}