#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
int main(){
	int i=0,j,k,D,d,f=0;
	string s,t;
	cin>>t>>s>>D;
	k=t.size();
	for(;i<=s.size()-k;i++){
		for(d=j=0;j<k;j++)d+=s[i+j]!=t[j];
		if(d<=D){
			if(f)cout<<' ';
			f=1;
			cout<<(i);
		}
	}
	cout<<endl;
}