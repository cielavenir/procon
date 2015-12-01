#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;
	cin>>s;
	string q;
	cin>>q;

	vector<int>a;
	a.push_back(-1);
	for(int i=1,k=-1;i<=q.size();i++){
		for(;k>=0&&q[i-1]!=q[k];)k=a[k];
		a.push_back(++k);
	}

	vector<int>r;
	for(int i=0,k=0;i<s.size();i++){
		for(;k>=0&&(k==q.size()||q[k]!=s[i]);)k=a[k];
		if(++k==q.size())r.push_back(i+1-k);
	}
	for(int i=0;i<r.size();i++)printf("%d\n",r[i]);
}