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
	for(cin>>f;cin>>f;){
		if(f[0]=='>')v.push_back(s),s="";
		else s+=f;
	}
	v.push_back(s);
	vector<string>::iterator it=min_element(v.begin(),v.end(),Len());
	f=*it;
	v.erase(it);
	int l=f.length(),k,i;
	for(;l>0;l--)for(k=0;k+l<=f.length();k++){
		s=f.substr(k,l);
		for(i=0;i<v.size();i++)if(v[i].find(s)==string::npos)break;
		if(i==v.size()){cout<<s<<endl;return 0;}
	}
}