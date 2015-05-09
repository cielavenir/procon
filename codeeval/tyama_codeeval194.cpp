//#include "inspect.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
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

void transpose(vector<vector<int> >&m){
	for(int i=0;i<m.size();i++)for(int j=0;j<i;j++)swap(m[i][j],m[j][i]);
}

int main(){
	string line;
	for(;getline(cin,line);){
		char d;
		int siz;
		vector<vector<int> >m;
		{
			vector<string>a=split(line,";");
			d=a[0][0];
			siz=strtol(a[1].c_str()+1,NULL,10);
			m.resize(siz);
			vector<string>b=split(a[2],"|");
			for(int i=0;i<siz;i++)m[i]=split_int(b[i]," ");
		}
		if(d=='U'||d=='D')transpose(m);
		if(d=='R'||d=='D')for(auto &&e:m)reverse(e.begin(),e.end());
		//left
		for(int y=0;y<siz;y++){
			int idx=0,prev=-1;
			for(int x=0;x<siz;x++){
				if(m[y][x])if(m[y][x]==prev){
					--idx;
					m[y][idx++]=m[y][x]*2;
					prev=-1;
				}else{
					m[y][idx++]=m[y][x];
					prev=m[y][x];
				}
			}
			for(;idx<siz;idx++)m[y][idx]=0;
		}
		if(d=='R'||d=='D')for(auto &&e:m)reverse(e.begin(),e.end());
		if(d=='U'||d=='D')transpose(m);
		for(int i=0;i<siz;i++)for(int j=0;j<siz;putchar(j<siz-1?' ':i<siz-1?'|':'\n'),j++)printf("%d",m[i][j]);
	}
}