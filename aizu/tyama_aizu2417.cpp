#include <map>
#include <string>
#include <iostream>
using namespace std;
int main(){
	map<char,string>m;
	m['T']="a";
	m['L']="i";
	m['U']="u";
	m['R']="e";
	m['D']="o";
	m['1']="";
	m['2']="k";
	m['3']="s";
	m['4']="t";
	m['5']="n";
	m['6']="h";
	m['7']="m";
	m['8']="y";
	m['9']="r";
	m['0']="w";
	string s,t;
	cin>>s;
	for(int i=0;i<s.length();i+=2){
		t=s.substr(i,2);
		if(t=="0U")cout<<"nn";
		else cout<<m[t[0]]<<m[t[1]];
	}
	cout<<endl;
}