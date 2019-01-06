#include <vector>
#include <set>
#include <cstdio>
using namespace std;

int main(){
	int N;
	long long W,tV=0,tW=0,x=0;
	scanf("%d%lld",&N,&W);
	vector<pair<long long,long long> >v(N);
	for(int i=0;i<N;i++){
		//atcoderABC032D, aizuDPL1H
		//scanf("%lld%lld",&v[i].first,&v[i].second);
		//atcoderdpD/E
		scanf("%lld%lld",&v[i].second,&v[i].first);
		tV+=v[i].first,tW+=v[i].second;
	}
	if(W>tW)W=tW;
	if(tW<10000000){
		vector<long long>bag(W+1);
		bag[0]=1;
		for(auto &e:v){
			x+=e.second;
			if(x>W)x=W;
			for(int j=x;j>=e.second;j--)if(bag[j-e.second]&&bag[j]<bag[j-e.second]+e.first)
				bag[j]=bag[j-e.second]+e.first;
		}
		for(int i=0;i<W;i++)bag[i+1]=max(bag[i+1],bag[i]);
		printf("%lld\n",bag[W]-1);
	}else if(tV<10000000){
		vector<long long>bag(tV+1);
		bag[0]=1;
		for(auto &e:v){
			x+=e.first;
			for(int j=x;j>=e.first;j--)if(bag[j-e.first]&&(!bag[j]||bag[j]>bag[j-e.first]+e.second))
				bag[j]=bag[j-e.first]+e.second;
		}
		int i=0,mi;
		for(;i<=tV;i++)if(bag[i]&&bag[i]-1<=W)mi=i;
		printf("%d\n",mi);
	}else if(N<=40){
		int n=N/2;
		set<pair<long long,long long> >se1,se2;
		for(int i=0;i<1<<n;i++){
			long long V=0,w=0;
			for(int j=0;j<n;j++)if(i&(1<<j))V+=v[j].first,w+=v[j].second;
			se1.emplace(w,V);
		}
		for(int i=0;i<1<<(N-n);i++){
			long long V=0,w=0;
			for(int j=0;j<(N-n);j++)if(i&(1<<j))V+=v[j+n].first,w+=v[j+n].second;
			se2.emplace(w,V);
		}
		for(auto it=se1.begin();it!=se1.end();){
			auto it2=it;
			for(++it2;it2!=se1.end()&&it->second>=it2->second;)it2=se1.erase(it2);
			++it;
		}
		for(auto it=se2.begin();it!=se2.end();){
			auto it2=it;
			for(++it2;it2!=se2.end()&&it->second>=it2->second;)it2=se2.erase(it2);
			++it;
		}
		long long r=0;
		for(auto &e1:se1){
			auto it=se2.lower_bound({W-e1.first+1,0});
			if(it!=se2.begin()){
				--it;
				r=max(r,e1.second+it->second);
			}
		}
		printf("%lld\n",r);
	}else{
		return 1;
	}
}
