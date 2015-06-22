#include <vector>
#include <algorithm>
#include <cstdio>
int main(){
	int n,vmax=0,tmax=0;
	scanf("%d",&n);
	std::vector<std::pair<int,int> >v(n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&v[i].first,&v[i].second);
		if(vmax<v[i].first)vmax=v[i].first;
		if(tmax<v[i].second)tmax=v[i].second;
	}
	std::sort(v.begin(),v.end(),[](const std::pair<int,int> &a,const std::pair<int,int> &b)->bool{return a.first+a.second<b.first+b.second;});
	std::vector<int>bag(tmax+vmax+1);
	bag[0]=1;
	for(int i=0;i<n;i++){
		for(int j=v[i].second-1;j>=0;j--)bag[j+v[i].first]|=bag[j];
	}
	for(int i=tmax+vmax;i>=0;i--)if(bag[i]){
		printf("%d\n",i);
		break;
	}
}