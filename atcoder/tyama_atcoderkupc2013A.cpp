#include <iostream>
#include <string>
using namespace std;
main(){
	int N,Q,n;
	string prev="kogakubu10gokan";
	cin>>N>>Q>>n;
	for(;n<=Q&&N--;)cin>>prev>>n;
	cout<<prev<<endl;
}