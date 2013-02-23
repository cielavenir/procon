#include <vector>
#include <algorithm>
#include <cstdio>
#define LIMIT 10000
using namespace std;
bool ck(vector<int>&v){
	for(int i=0;i<v.size();i++)if(v[i]!=i+1)return false;
	return true;
}
main(){
	int n,i,j,s,x,l;
	vector<int>tri;
	for(i=1;i<199;i++)tri.push_back(i*(i+1)/2);
	for(;scanf("%d",&n),n;){
		vector<int>v;
		for(s=i=0;i<n;i++){
			scanf("%d",&x);
			s+=x;
			v.push_back(x);
		}
		vector<int>::iterator idx=find(tri.begin(),tri.end(),s);
		i=LIMIT+1;
		if(idx!=tri.end()){
			for(i=0;i<=LIMIT&&!ck(v);i++){
				l=v.size();
				for(j=0;j<l;j++)v[j]--;
				v.erase(remove(v.begin(),v.end(),0),v.end());
				v.push_back(l);
			}
		}
		printf("%d\n",i>LIMIT?-1:i);
	}
}