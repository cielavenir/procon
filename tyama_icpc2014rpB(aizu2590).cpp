#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
int ck(int N,long long mask){
	int c=-1;
	long long k=1;
	for(int i=0;i<N;i++,k<<=1)
		if(mask&k){
			if(c>=0)c=-2;
			if(c==-1)c=i;
		}
	return c;
}
int main(){
	for(int N,M,Q;cin>>N>>M>>Q,N;){
		vector<long long>v0(M);
		vector<long long>v1(M);
		string prev(M,'0');
		{
			long long mask=0,k=1;
			for(int i=0;i<N;i++,k<<=1)mask|=k;
			for(int i=0;i<M;i++)v0[i]=v1[i]=mask;
		}
		for(;Q--;){
			string s,t;
			cin>>s>>t;
			long long mask0=0,mask1=0,k=1;
			for(int i=0;i<N;i++,k<<=1)(s[i]=='0'?mask0:mask1)|=k;
			for(int i=0;i<M;i++)
				if(!(prev[i]^t[i]))
					v0[i]&=mask0;
				else
					v1[i]&=mask1;
			prev=t;
		}
		for(int j=0;j<M;j++){
			int i=0,c[3]={ck(N,v0[j]),ck(N,v1[j]),ck(N,v1[j]&v0[j])};
			for(;i<3;i++)if(c[i]>=0){putchar(c[i]<10?c[i]+'0':c[i]-10+'A');break;}
			if(i==3)putchar('?');
		}
		puts("");
	}
}