#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
main(){
	int i=0,j,k,D=2,d;
	string s="AACAAGCTGATAAACATTTAAAGAG",t="AAAAA";
	//cin>>t>>s>>D;
	k=t.size();
	for(;i<s.size()-k;i++){
		for(d=j=0;j<k;j++)d+=s[i+j]!=t[j];
		if(d<=D)cout<<(i)<<endl;
	}
}