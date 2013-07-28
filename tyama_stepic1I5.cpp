#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
int main(){
	int i=0,j,k,D,d;
	string s,t;
	cin>>t>>s>>D;
	k=t.size();
	for(;i<s.size()-k;i++){
		for(d=j=0;j<k;j++)d+=s[i+j]!=t[j];
		if(d<=D)cout<<(i)<<endl;
	}
}