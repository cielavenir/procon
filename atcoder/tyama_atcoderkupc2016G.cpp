#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
struct SAComp{
	const int h,*g;
	SAComp(const int h, const int* g) : h(h), g(g) {}
	bool operator()(const int a, const int b){
		return a == b ? false : g[a] != g[b] ? g[a] < g[b] : g[a+h] < g[b+h];
	}
};
vector<int> buildSA(const string &t){
	int n=t.size();
	int g[n],b[n];
	vector<int>suff(n);
	for(int i=0;i<n;i++)suff[i]=i,g[i]=t[i];
	b[0]=b[n-1]=0;
	sort(suff.begin(),suff.end(),SAComp(0,g));
	for(int h=1;b[n-1]!=n-1;h<<=1){
		SAComp comp(h,g);
		sort(suff.begin(),suff.end(),comp);
		for(int i=0;i<n-1;i++)b[i+1]=b[i]+comp(suff[i],suff[i+1]);
		for(int i=0;i<n;i++)g[suff[i]]=b[i];
	}
	return suff;
}
vector<int> buildLCP(const string &t, const vector<int> &suff){
	int n=t.size();
	int rank[n];
	vector<int>lcp(n);
	for(int i=0;i<n;i++)rank[suff[i]]=i;
	lcp[0]=0;
	for(int h=0,i=0;i<n-1;i++){
		int j=suff[rank[i]-1];
		if(h>0)h--;
		for(;j+h<n && i+h<n; h++){
			if(t[j + h]!=t[i + h])break;
		}
		lcp[rank[i]-1]=h;
	}
	return lcp;
}
int main(){
	int T;
	string s;cin>>s;s+='$';
	vector<int> suff=buildSA(s),lcp=buildLCP(s,suff);
	cout<<s.size()-1-*max_element(lcp.begin(),lcp.end())<<endl;
}
