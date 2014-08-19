#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int main(){
	int i,j;
	vector<int>v;
	string s;
	cin>>s;
	for(i=0;i<=(int)s.size()-8;i++){
		map<char,int>m;
		for(j=0;j<8;j++)m[s[i+j]]++;
		if(m['A']==2 && m['D']==1 && m['I']==1 && m['N']==2 && m['U']==1 && m['Y']==1)v.push_back(i);
	}
	for(i=0;i<v.size();i++)for(j=0;j<8;j++)s[v[i]+j]="AIZUNYAN"[j];
	cout<<s<<endl;
}