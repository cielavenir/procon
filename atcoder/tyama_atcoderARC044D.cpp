#include<iostream>
#include<string>
using namespace std;
int main(){
	int N,T,i;
	cin>>N;
	wstring A(N,0),B(N+1,0),s(N,65);
	for(B[N]=i=-1;++i<N;B[A[i]=--T]=i)cin>>T;
	for(T=i=0;++i<N;s[A[i]]+=T)T+=B[A[i-1]+1]>=B[A[i]+1];
	wcout<<(T>25?L"-1":s)<<endl;
}