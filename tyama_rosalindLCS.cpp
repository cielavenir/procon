#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
struct Len{
	bool operator()(const string& x, const string& y) const {return x.length()<y.length();}
};
int main(){
	string f,s;
	vector<string>v;
	for(;cin>>s;)v.push_back(s);
	sort(v.begin(),v.end(),Len());
	f=v[0];
	v.erase(v.begin());
	int l=f.length(),k,i;
	for(;l>0;l--)for(k=0;k+l<=f.length();k++){
		s=f.substr(k,l);
		for(i=0;i<v.size();i++)if(v[i].find(s)==string::npos)break;
		if(i==v.size()){cout<<s<<endl;return 0;}
	}
}