#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	string s;
	vector<int>v;
	int i;
	for(;cin>>s;)for(i=0;i<s.length();i++)v.push_back(s.length());
	sort(v.begin(),v.end());
	cout<<((v.size()&1)?(v[v.size()/2]+v[v.size()/2+1])/2:v[v.size()/2])<<' '<<((v.size()&2)?(v[v.size()/4]+v[v.size()/4+1])/2:v[v.size()/4])<<endl;
}