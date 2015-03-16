#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	vector<int>v(N);
	for(;M--;){
		int a,l;
		scanf("%d%d",&a,&l);
		for(int i=0;i<l;i++)v[(a+i)%N]=1;
	}
	rotate(v.begin(),min_element(v.begin(),v.end()),v.end());

	map<int,int>m;
	for(int i=0,c=0,x=0;i<N;i++){
		if(x&&!v[i]){
			m[-c]++;
			c=0;
		}else if(v[i]){
			c++;
		}
		x=v[i];
		if(i==N-1&&c)m[-c]++;
	}
	for(auto &e:m){
		printf("%d %d\n",-e.first,e.second);
	}
}