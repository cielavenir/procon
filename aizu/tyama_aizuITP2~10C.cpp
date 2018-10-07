#include <iostream>
#include <bitset>
using namespace std;
typedef bitset<64> b64;
int main(){
	b64 b;
	int q,a,x;
	for(cin>>q;q--;){
		cin>>a;
		if(a==0)cin>>x,cout<<b[x]<<endl;
		if(a==1)cin>>x,b[x]=1;
		if(a==2)cin>>x,b[x]=0;
		if(a==3)cin>>x,b[x]=b[x]^1;
		if(a==4)cout<<b.all()<<endl;
		if(a==5)cout<<b.any()<<endl;
		if(a==6)cout<<b.none()<<endl;
		if(a==7)cout<<b.count()<<endl;
		if(a==8)cout<<b.to_ulong()<<endl;
	}
}
