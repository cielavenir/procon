#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
	int H,W,D,K;
	cin>>H>>W>>D>>K;
	vector<pair<int,int> >v(D);
	map<pair<int,int>,int>m;
	for(int i=0;i<D;i++)cin>>v[i].first>>v[i].second;
	for(int i=0;i<D&&i<K;i++){
		int ht=i/W;
		int wt=i%W;
		if(ht%2)wt=W-1-wt;
		if(ht==v[i].first && wt==v[i].second){K++;continue;}
		cout<<ht<<' '<<wt<<' '<<v[i].first<<' '<<v[i].second<<endl;
		pair<int,int> z={ht,wt};
		auto it=m.find(z);
		if(it!=m.end()){
			int k=it->second;
			m[{v[i].first,v[i].second}]=k;
			v[k]={v[i].first,v[i].second};
		}
		m[z]=i;
		v[i]=z;
	}
}
