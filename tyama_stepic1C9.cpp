/*
input:
https://app.box.com/rosalinddata/1/787051127/9160600981/1
https://app.box.com/download/external/f_9160600981/0/Vibrio_cholerae.txt?vanity_name=rosalinddata
*/
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
int main(){
	int i=0,k;
	string line,s,t="ATGATCAAG";
	//getline(cin,line);
	//for(;getline(cin,line);)s+=line;
	cin>>s;
	k=t.size();
	for(;i<s.size()-k;i++){
		if(s.substr(i,k)==t)cout<<(i+1)<<endl;
	}
}