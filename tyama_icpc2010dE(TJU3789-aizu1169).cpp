#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

typedef pair<string,int> P;
map<int,vector<P> >arr;
int N,S,G;

void bfs(){
	set<P>q;
	q.insert(make_pair("",S));
	for(;!q.empty();){
		P p=*q.begin();q.erase(q.begin());
		if(p.second==G){cout<<p.first<<endl;return;}
		if(p.first.length()>=N*6){cout<<"NO"<<endl;return;}
		vector<P> a=arr[p.second];
		if(!a.empty()){
			string prefix=a[0].first;
			for(int i=0;i<a.size();i++){
				if(a[i].first.substr(0,prefix.length())!=prefix)break;
				q.insert(make_pair(p.first+a[i].first,a[i].second));
			}
		}
	}
}

int r[40][40];
int main(){
	int a,i,j,k;
	map<int,vector<P> >::iterator it;
	vector<P>::iterator it2;
	for(;cin>>N>>a>>S>>G,N;){
		memset(r,0,sizeof(r));
		arr.clear();
		int _a,_b;string _s;
		for(;a;a--)cin>>_a>>_b>>_s,arr[_a].push_back(make_pair(_s,_b)),r[_a][_b]=1;
		for(k=0;k<N;k++)
			for(r[k][k]=1,i=0;i<N;i++)
				for(j=0;j<N;j++)
					r[i][j]|=r[i][k]&r[k][j];
		if(!r[S][G]){cout<<"NO"<<endl;continue;}
		for(it=arr.begin();it!=arr.end();it++){
			vector<P> &x=it->second;
			for(it2=x.begin();it2!=x.end();)
				if(!r[it2->second][G])x.erase(it2);else it2++;
			sort(x.begin(),x.end());
		}
		bfs();
	}
}