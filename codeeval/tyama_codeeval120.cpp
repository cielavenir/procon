#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

vector<string> split(string &str, const char *delim){
	vector<string> result;
	int cutAt;
	while( (cutAt = str.find_first_of(delim)) != str.npos ){
		if(cutAt > 0){
			result.push_back(str.substr(0, cutAt));
		}
		str = str.substr(cutAt + 1);
	}
	if(str.length() > 0){
		result.push_back(str);
	}
	return result;
}
vector<int> split_int(string &str, const char *delim){
	vector<int> result;
	int cutAt;
	while( (cutAt = str.find_first_of(delim)) != str.npos ){
		if(cutAt > 0){
			result.push_back(strtol(str.substr(0, cutAt).c_str(),NULL,10));
		}
		str = str.substr(cutAt + 1);
	}
	if(str.length() > 0){
		result.push_back(strtol(str.c_str(),NULL,10));
	}
	return result;
}

char h[20001];
int main(){
	int i,j,M,m;
	string line;
	for(;getline(cin,line);){
		M=0,m=20000;
		memset(h,0,sizeof(h));
		line=line.substr(1);
		vector<string>a=split(line,"(");
		for(i=0;i<a.size();i++){
			vector<int>b=split_int(a[i],",");
			b[0]=b[0]*2,b[2]=b[2]*2;
			if(b[0]<m)m=b[0];
			if(M<b[2])M=b[2];
			for(j=b[0];j<=b[2];j++)h[j]=max(h[j],(char)b[1]);
		}
		printf("%d %d",m/2,h[m]);j=h[m];
		for(i=m;i<=M;i+=2){
			if(j<h[i])printf(" %d %d",i/2,h[i]),j=h[i];
			if(j>h[i+1])printf(" %d %d",i/2,h[i+1]),j=h[i+1];
		}
		puts("");
	}
}