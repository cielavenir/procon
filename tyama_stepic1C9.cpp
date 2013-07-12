#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
main(){
	int i=0,k;
	string line,s,t="ATGATCAAG";
	getline(cin,line);
	for(;getline(cin,line);)s+=line;
	k=t.size();
	for(;i<s.size()-k;i++){
		if(s.substr(i,k)==t)cout<<(i+1)<<endl;
	}
}