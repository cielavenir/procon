#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
vector<string>V={
	"ABCD",
	"BADC",
	"CDAB",
	"DCBA",
};
int main(){
	int N,K,cycle;
	string t,nxt;
	cin>>N>>K>>t;
	const string s=t;
	do{
		nxt=t; //allocate
		for(int i=0;i<s.size();i++)nxt[i]=V[t[i]-'A'][t[(i+1)%s.size()]-'A'];
		t=nxt;
		cycle+=1;
		if(cycle==K){cout<<t<<endl;return 0;}
	}while(s!=t);
	K%=cycle;
	for(;K--;){
		nxt=t; //allocate
		for(int i=0;i<s.size();i++)nxt[i]=V[t[i]-'A'][t[(i+1)%s.size()]-'A'];
		t=nxt;
	}
	cout<<t<<endl;return 0;
}