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
vector<int> buildLCP(const string &t, const vector<int> &suff, vector<int> &rank){
	int n=t.size();
	rank.resize(n);
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

#define INF 9999999
class RMQ{
	int size;
	vector<int> minval;
	vector<int> maxval;
	pair<int,int> _query(int a,int b,int k,int l, int r){
		if(r<=a||b<=l)return make_pair(INF,-INF);
		if(a<=l&&r<=b)return make_pair(minval[k],maxval[k]);
		else{
			pair<int,int> vl=_query(a,b,k*2+1,l,(l+r)/2);
			pair<int,int> vr=_query(a,b,k*2+2,(l+r)/2,r);
			return make_pair(min(vl.first,vr.first),max(vl.second,vr.second));
		}
	}

public:
	RMQ(int k){init(k);}
	void init(int k){
		for(size=1;size<k;)size<<=1;
		//size=1<<(32-__builtin_clz(k));
		minval=vector<int>(2*size-1,INF);
		maxval=vector<int>(2*size-1,-INF);
	}

	void update(int k,int t){
		k+=size-1;
		minval[k]=maxval[k]=t;
		while(k>0){
			k=(k-1)/2;
			minval[k]=min(minval[k*2+1],minval[k*2+2]);
			maxval[k]=max(maxval[k*2+1],maxval[k*2+2]);
		}
	}

	pair<int,int> query(int a,int b){
		return _query(a,b,0,0,size);
	}
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;
	cin>>s;
	cin>>s;
	s+='$';
	int n=s.size();
	vector<int> suff=buildSA(s);
	vector<int> rank;
	vector<int> lcp=buildLCP(s, suff, rank);
	RMQ rmq(n);
	for(int i=0;i<n;i++)rmq.update(i, lcp[i]);
	int r=0;
	for(int i=0;i<n;i++){
	  for(int j=i+1;j<n;j++){
		int z=rmq.query(min(rank[i],rank[j]),max(rank[i],rank[j])).first;
	    r=max(r,min(j-i,z));
	  }
	}
	printf("%d\n",r);
}
