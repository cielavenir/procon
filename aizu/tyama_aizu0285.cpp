#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	vector<string>v={""};
	int x,y;
	cin>>x>>y;
	if(x==6&&y==4)x=4,y=4,v={"AA"};
	if(x==5&&y==5)x=4,y=4,v={"AB","BA"};
	if(x==4&&y==6)x=4,y=4,v={"BB"};
	if(x==5)x=4,v={"A"};
	if(y==5)y=4,v={"B"};
	string perm;
	for(;x--;)perm+='A';
	for(;y--;)perm+='B';
	do{
		for(auto &e:v)cout<<perm<<e<<endl;
	}while(next_permutation(perm.begin(),perm.end()));
}