#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main(){
	int N,R=0;
	map<string,int>m;
	for(cin>>N;N--;){
		string s,t;
		cin>>s>>t>>t;
		transform(s.begin(),s.end(),s.begin(),::tolower);
		transform(t.begin(),t.end(),t.begin(),::tolower);
		if(m.find(t)==m.end())m[s]=2;
		else m[s]=m[t]+1;
		if(R<m[s])R=m[s];
	}
	cout<<R<<endl;
}