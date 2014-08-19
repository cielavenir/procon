#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
struct C{bool operator()(string &a,string &b){return a.size()>b.size();}};
main(){
	vector<string>v;
	string s;
	int n,i;
	cin>>n;
	for(getline(cin,s);getline(cin,s);)v.push_back(s);
	sort(v.begin(),v.end(),C());
	for(i=0;i<n;i++)cout<<v[i]<<endl;
}