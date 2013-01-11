#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;

vector<vector<int> >v;
vector<pair<int,int> >r;
set<int>oc;
set<int>fr;
set<int>::iterator ifr;
main(){
	int N,M,i,j,n,x,y=200,z;
	scanf("%d%d",&N,&M);
	for(i=0;i<M;i++){
		scanf("%d",&n);
		vector<int> _v;
		for(j=0;j<n;j++){
			scanf("%d",&x);
			_v.push_back(x);
			oc.insert(x);
		}
		v.push_back(_v);
	}
	for(i=1;i<=N;i++){
		if(find(oc.begin(),oc.end(),i)==oc.end())fr.insert(i);
	}
	//ifr=fr.begin();
	//while(ifr!=fr.end()){
	//	printf("%d",*ifr);
	//	ifr++;
	//}
	for(z=1;z<=N;){
		vector<int> _v;
		for(i=0;i<=M;i++){
			_v=v[i];
			if(find(_v.begin(),_v.end(),j)!=_v.end())break;
		}
		//defrag file v[i]
		if(_v[0]!=z){
			r.push_back(make_pair(_v[0],*(fr.begin())));
			vector<int>::iterator i_v=find(_v.begin(),_v.end(),z);
			r.push_back(make_pair(*i_v,z));
		}
		z+=_v.size();
	}
}

	