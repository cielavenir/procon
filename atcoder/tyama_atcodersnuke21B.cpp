#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int K;
	string S;
	cin>>K>>S;
	set<int>se;
	int i,j;
	for(i=0;i<S.size();i=j){
		for(;i<S.size()&&S[i]!='s';i++);
		for(j=i;j<S.size()&&S[j]=='s';j++);
		if(j<S.size()&&S[j]<'s')for(;i<j&&se.size()<K;i++)se.insert(i);
	}
	for(int i=S.size()-1;i>=0&&se.size()<K;i--){
		if(S[i]=='s')se.insert(i);
	}
	vector<int>v(se.begin(),se.end());
	//sort(v.begin(),v.end());
	for(i=j=0;i<S.size();i++){
		if(j<v.size()&&i==v[j])j++;
		else putchar(S[i]);
	}
	puts("");
}