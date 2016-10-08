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
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;
	cin>>s;
	s+='$';
	int n=s.size();
	vector<int>suff=buildSA(s);
	vector<pair<char,int>>sorted(n);
	for(int i=0;i<n;i++)sorted[i]={s[(suff[i]-1+n)%n],i};
	sort(sorted.begin(),sorted.end());

	int T;
	for(cin>>T;T--;){
		string q;
		cin>>q;
		int start=0,stop=n,idx=q.size()-1;
		for(;idx>=0;idx--){
			pair<char,int> ql={q[idx],start},qr={q[idx],stop};
			start=lower_bound(sorted.begin(),sorted.end(),ql)-sorted.begin();
			stop=lower_bound(sorted.begin(),sorted.end(),qr)-sorted.begin();
			if(start==stop)break;
		}
		if(idx<0){
			//{vector<int>v;for(;start<stop;start++)v.push_back(suff[start]);sort(v.begin(),v.end());for(auto &e:v)printf("%d\n",e);}
			puts("1");
		}else{
			puts("0");
		}
	}
}
