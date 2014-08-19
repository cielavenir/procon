#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
int main(){
	int i=0,k,f=0;
	string s,t;
	cin>>t>>s;
	k=t.size();
	for(;i<s.size()-k;i++){
		if(s.substr(i,k)==t){
			if(f)cout<<' ';
			f=1;
			cout<<(i+0);
		}
	}
	cout<<endl;
}