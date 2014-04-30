#include <vector>
#include <set>
#include <map>
#include <cstdio>
using namespace std;
typedef vector<int> vi;
int main(){
	set<vi> result;
	for(int I=0;I<6*6*6*6*6*6;I++){
		vi v={
			I/6/6/6/6/6+1,
			I/6/6/6/6%6+1,
			I/6/6/6%6+1,
			I/6/6%6+1,
			I/6%6+1,
			I%6+1,
		};
		map<vi,int> me;
		vector<vi> ve;
		for(;;){
			if(me.find(v)!=me.end())break;
			me[v]=ve.size();
			ve.push_back(v);
			int n=v[0];
			for(int i=0;i<n;i++)v[i]=7-v[i];
			rotate(v.begin(),v.begin()+n,v.end());
		}
		int n=me[v];
		for(int i=0;i<n;i++)result.insert(ve[i]);
	}
	printf("%d\n",result.size()); // 28908
/*
	for(auto it=result.begin();it!=result.end();++it){
		printf("%d%d%d%d%d%d\n",it->at(0),it->at(1),it->at(2),it->at(3),it->at(4),it->at(5));
	}
*/
}