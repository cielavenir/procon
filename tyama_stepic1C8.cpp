#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
main(){
	int i=0,k;
	string s,t;
	cin>>s>>t;
	k=t.size();
	for(;i<s.size()-k;i++){
		if(s.substr(i,k)==t)cout<<(i+1)<<endl;
	}
}