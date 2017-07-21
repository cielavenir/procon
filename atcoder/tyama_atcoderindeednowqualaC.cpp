#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int main(){
	int N,M,x;
	scanf("%d",&N);
	vector<int>v;
	for(int i=1;i<=N;i++){
		scanf("%d",&x);
		if(x)v.push_back(x);
	}
	sort(v.begin(),v.end());
	for(scanf("%d",&M);M--;){
		scanf("%d",&x);
		if(v.size()<=x){
			puts("0");
			//v.resize(0);
		}else{
			int val=v[v.size()-1-x]; //入れない人で最大の点数
			printf("%d\n",val+1);
			//auto it=upper_bound(v.begin(),v.end(),val);
			//v.resize(distance(v.begin(),--it));
		}
	}
}
