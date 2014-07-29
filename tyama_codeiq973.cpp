#include <queue>
#include <map>
#include <algorithm>
#include <numeric>
#include <cstdio>
using namespace std;

int main(){
	int T=0,N=7; //9;
	vector<int>v(N);
	iota(v.begin(),v.end(),1);
	queue<vector<int>>q;
	map<vector<int>,int>m;
	q.push(v);
	m[v]=0;
	for(;!q.empty();){
		vector<int> prev=q.front();q.pop();
		vector<int> v=prev;
		for(int i=0;i<N-1;i++)for(int j=i+1;j<N;j++){
			swap(v[i],v[j]);
			if(m.find(v)==m.end()){
				q.push(v);
				m[v]=m[prev]+1;
			}
			swap(v[i],v[j]);
		}
	}
	for(auto it=m.begin();it!=m.end();++it)T+=it->second;
	printf("%d\n",T); //22212
}