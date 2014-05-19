#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef pair<string,pair<int,int> > pspii;
int m=0;
vector<pspii>ma,data;
void dfs(vector<pspii> &a,int asize,int i){
	if(m<asize){
		printf("%d",asize);
		for(int j=0;j<asize;j++)printf(" %s",a[j].first.c_str());
		puts("");
		ma=a;
		m=asize;
	}
	for(int j=i;j<data.size();j++){
		if(a[asize-1].second.second<data[j].second.first){
			a.push_back(data[j]);
			dfs(a,asize+1,j+1);
			a.pop_back();
		}
	}
}
int main(){
	int i1,i2,i3,i4;
	string s,t;
	for(;cin>>s>>t;){
		sscanf(t.c_str(),"%d/%d-%d/%d",&i1,&i2,&i3,&i4);
		data.push_back(make_pair(s,make_pair(i1*100+i2,i3*100+i4)));
	}
	sort(data.begin(),data.end(),[](pspii &a,pspii &b){return a.second.first<b.second.first;});
	vector<pspii> a;
	for(int i=0;i<data.size();i++){
		printf("%d\n",i);
		a.push_back(data[i]);
		dfs(a,1,i+1);
		a.pop_back();
	}
}