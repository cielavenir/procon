#include <iostream>
#include <string>
#include <vector>
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

#define M 10000
short P[M],A[M],B[M]; //decreasing memory will give you bonus points...
int R(int a){return P[a]==a?a:(P[a]=R(P[a]));}

int main(){
	int i,k,x,y,d;
	string line;
	for(;getline(cin,line);){
		int begin=-1,end=-1;
		for(k=0;k<M;k++)A[k]=B[k]=0,P[k]=k;
		if(line=="BEGIN-END"){puts("GOOD");continue;}
		{
			vector<string>a=split(line,";");
			for(d=i=0;i<a.size();i++){
				vector<string>b=split(a[i],"-");
				if(b[1]=="BEGIN"||b[0]=="END")d=1;
				else if(b[0]=="BEGIN"){
					if(begin!=-1)d=1;
					begin=strtol(b[1].c_str(),NULL,10);
				}else if(b[1]=="END"){
					if(end!=-1)d=1;
					end=strtol(b[0].c_str(),NULL,10);
				}else{
					A[x=strtol(b[0].c_str(),NULL,10)]++;
					B[y=strtol(b[1].c_str(),NULL,10)]++;
					P[R(x)]=R(y);
				}
			}
		}
		if(d==1||begin==-1||end==-1)puts("BAD");
		else{
			for(d=k=0;k<M;k++){
				d=A[k]-B[k];
				if(k==begin){
					d=d==1;
				}else if(k==end){
					d=d==-1;
				}else{
					d=d==0;
				}
				if(!d||((A[k]|B[k])&&R(begin)!=R(k)))break;
			}
			puts(k==M ? "GOOD" : "BAD");
		}
	}
}