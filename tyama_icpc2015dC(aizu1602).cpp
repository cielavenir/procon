#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef vector<pair<int,string> > vpis;
int parse(const vpis &v,int l,int r){
	if(v[l].second!="+"&&v[l].second!="*")return strtol(v[l].second.c_str(),NULL,10);
	int unit=v[l].second=="+"?0:1;
	for(int i=l+1;i<r;){
		int j=i+1;
		if(v[i].second=="+"||v[i].second=="*"){
			for(;j<v.size()&&v[j].first>v[i].first;j++);
		}
		int n=parse(v,i,j);
		i=j;
		if(v[l].second=="+")unit+=n;
		else unit*=n;
	}
	return unit;
}
int main(){
	int N;
	string s;
	for(;cin>>N,N;){
		vpis v(N);
		for(int i=0;i<N;i++){
			cin>>s;
			int idx=0;
			for(;s[idx]=='.';idx++);
			v[i]=make_pair(idx,s.substr(idx));
		}
		printf("%d\n",parse(v,0,N));
	}
}