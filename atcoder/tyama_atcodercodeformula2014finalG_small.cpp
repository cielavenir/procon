#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
	vector<pair<int,int> > result;
	int n;
	scanf("%d",&n);
	if(n>1000)return 1;
	vector<int>v1(n),v2;
	for(int i=0;i<n;i++)scanf("%d",&v1[i]);
	for(;n;n--){
		vector<int>::iterator it1=find(v1.begin(),v1.end(),n);
		vector<int>::iterator it2=find(v2.begin(),v2.end(),n);
		if(it1!=v1.end()){
			int d=distance(v1.begin(),it1);
			for(;v1.size()>d+1;){
				v2.push_back(v1[v1.size()-1]);
				v1.erase(v1.begin()+v1.size()-1);
				result.push_back(make_pair(1,2));
			}
			v1.erase(v1.begin()+d);
			result.push_back(make_pair(1,3));
		}else{
			int d=distance(v2.begin(),it2);
			for(;v2.size()>d+1;){
				v1.push_back(v2[v2.size()-1]);
				v2.erase(v2.begin()+v2.size()-1);
				result.push_back(make_pair(2,1));
			}
			v2.erase(v2.begin()+d);
			result.push_back(make_pair(2,3));
		}
	}
	printf("%d\n",result.size());
	for(int i=0;i<result.size();i++)printf("%d %d\n",result[i].first,result[i].second);
}