#include <iostream>
#include <string>
using namespace std;
int z[100001];
main(){
	string s;
	int T,a,b;
	cin>>s;
	for(a=1;a<s.size();a++){
		z[a]=z[a-1]+(s[a]==s[a-1]);
	}
	for(cin>>T;T--;cout<<z[b-1]-z[a-1]<<endl)cin>>a>>b;
}