#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
const char *bases="ATGC";
const char *cbases="TACG";
string revcom(string &s){
	string t=s;
	reverse(t.begin(),t.end());
	for(int i=0;i<t.size();i++){
		const char *p=strchr(bases,t[i]);
		if(p)t[i]=cbases[p-bases];
	}
	return t;
}
int main(){
	string s;
	cin>>s;
	cout<<revcom(s)<<endl;
}