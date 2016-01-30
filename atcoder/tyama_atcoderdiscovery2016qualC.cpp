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

int main(){
	string S;
	int K;
	cin>>S>>K;
	if(count(S.begin(),S.end(),'a')+K>=S.size()){
		cout<<string(S.size()-K,'a')<<endl;
		return 0;
	}
	vector<int> sa=buildSA(S+'$');
	int i=0,j=0,tail=-1;
	for(;i<=K;){
		if(S[i+j]=='a')tail=i+j,j++;
		else i++;
	}
	//assert(tail+1<=j+K);
	int rn=tail+1;
#if 1
	for(int k=1;k<=S.size();k++)if(tail<sa[k]&&sa[k]<=j+K){rn=sa[k];break;}
#else
	string r=S.substr(tail+1);
	for(int k=tail+2;k<=j+K;k++){
		if(r>sa[k]){
			r=S.substr(k);
			rn=k;
		}
	}
#endif
	for(int i=0;i<rn;i++)S[i]='a';
	cout<<string(j+K-rn,'a')+S<<endl;
}