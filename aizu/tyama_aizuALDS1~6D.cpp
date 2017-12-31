//プログラミングコンテスト攻略のためのアルゴリズムとデータ構造 P181-182(Google Booksプレビュー)による.

#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;

int do_cycle(vector<int> &v,int x){
	int s=0,m=1<<30;
	for(auto &e:v)s+=e,m=min(m,e);
	return min(s+(v.size()-2)*m,s+m+(v.size()+1)*x);
}

int main(){
	int N,x=1<<30,r=0;
	scanf("%d",&N);
	vector<int>v(N),b(N),se(N);
	map<int,int>m;
	vector<vector<int> >cycles;
	for(int i=0;i<N;i++)scanf("%d",&v[i]),x=min(x,v[i]),se[i]=v[i];
	sort(se.begin(),se.end());
	int i=0;for(auto &e:se){m[e]=i++;}
	for(int i=0;i<N;i++)if(!b[i]){
		vector<int>cycle;
		int k=i;
		do{
			cycle.push_back(se[k]);
			b[k]=1;
			k=m[v[k]];
		}while(k!=i);
		r+=do_cycle(cycle,x);
	}
	printf("%d",r);
}
