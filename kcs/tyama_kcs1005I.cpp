#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int i,n,x,rank;
	scanf("%d",&n);
	vector<pair<int,int> >v;
	for(i=0;i<n;i++)scanf("%d",&x),v.push_back(make_pair(-x,i));
	sort(v.begin(),v.end());
	vector<int>r(n);
	rank=r[0]=x=1;
	for(i=1;i<n;i++){
		if(v[i-1].first<v[i].first){
			rank+=x;
			x=1;
		}else{
			x++;
		}
		r[i]=rank;
	}
	vector<pair<int,int> >ret;
	for(i=0;i<n;i++)ret.push_back(make_pair(v[i].second,r[i]));
	sort(ret.begin(),ret.end());
	for(i=0;i<n;i++)printf("%d\n",ret[i].second);
}