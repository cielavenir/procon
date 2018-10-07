#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
typedef bitset<64> b64;
int main(){
	b64 b;
	int n,x;
	cin>>n;
	vector<b64> v(n);
	for(int i=0,j;i<n;i++)for(cin>>j;j--;v[i][x]=1)cin>>x;
	int q,a;
	for(cin>>q;q--;){
		cin>>a;
		if(a==0)cin>>x,cout<<b[x]<<endl;
		if(a==1)cin>>x,b|=v[x];
		if(a==2)cin>>x,b&=~v[x];
		if(a==3)cin>>x,b^=v[x];
		if(a==4)cin>>x,cout<<((b&v[x])==v[x])<<endl;
		if(a==5)cin>>x,cout<<(b&v[x]).any()<<endl;
		if(a==6)cin>>x,cout<<(b&v[x]).none()<<endl;
		if(a==7)cin>>x,cout<<(b&v[x]).count()<<endl;
		if(a==8)cin>>x,cout<<(b&v[x]).to_ulong()<<endl;
	}
}
