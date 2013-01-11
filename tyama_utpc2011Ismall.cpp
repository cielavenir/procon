#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <cstdio>
#define BIT(x,n) ((x>>n)&1)
using namespace std;
string itos(int i){stringstream ss;ss<<i;return ss.str();}
int main(){
	int N,f,t,i=0,j,taint=0;
	map<int,int> m0,m1;
	map<int,string> M;
	for(cin>>N;i<N;i++){
		cin>>f>>t;
		for(j=0;j<8;j++)
			if(BIT(f,j)){
				if(m1.find(j)!=m1.end()&&m1[j]!=BIT(t,j))taint=1;
				m1[j]=BIT(t,j);
			}else{
				if(m0.find(j)!=m0.end()&&m0[j]!=BIT(t,j))taint=1;
				m0[j]=BIT(t,j);
			}
	}
	if(taint){cout<<"(x)"<<endl;return 0;} //small, fixme
	for(i=0;i<8;i++){
		if(!m0[i]&&!m1[i])M[i]="0";
		if(m0[i]&&m1[i])M[i]=itos(1<<i);
		if(!m0[i]&&m1[i])M[i]=string("(x&")+itos(1<<i)+string(")");
		if(m0[i]&&!m1[i])M[i]=string("((~x)&")+itos(1<<i)+string(")");
	}
	for(i=0;i<7;i++)cout<<"("<<M[i]<<"|";
	cout<<M[7]<<")))))))"<<endl;
}