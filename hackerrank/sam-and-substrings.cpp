#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	string s;
	cin>>s;
	long long tmp=0,ret=0,mod=1000000007;
	for(int i=0;i<s.size();i++){
		tmp=((tmp*10)+(i+1)*(s[i]-'0'))%mod;
		ret=(ret+tmp)%mod;
	}
	cout<<ret<<endl;
}