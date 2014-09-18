#include <vector>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cstdio>
using namespace std;

int main(){
	int i,N,E,a,b,c;
	scanf("%d%d",&N,&E);
	if(N>9)return 1;
	vector<tuple<int,int,int>>v(E);
	for(i=0;i<E;i++){
		scanf("%d%d%d",&a,&b,&c);
		v[i]=make_tuple(a-1,b-1,c);
	}
	vector<int>p(N);
	iota(p.begin(),p.end(),0);
	c=0;
	do{
		for(b=a=0;a<E;a++){
			//wtf?
			if(
				distance(p.begin(),find(p.begin(),p.end(),get<0>(v[a]))) <
				distance(p.begin(),find(p.begin(),p.end(),get<1>(v[a])))
			)b+=get<2>(v[a]);
		}
		if(c<b)c=b;
	}while(next_permutation(p.begin(),p.end()));
	printf("%d\n",c);
}