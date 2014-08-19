#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int i=0,j=0,n;
	vector<string>v,u;
	for(cin>>n;j<n;j++){
		string s;
		cin>>s;
		v.push_back(s);
	}
	for(;i<n;i++)for(j=0;j<n;j++)if(i!=j){
		string s=v[i]+v[j];
		u.push_back(s);
	}
	sort(u.begin(),u.end());
	cout<<u[0]<<endl;
}