#include <vector>
#include <cstdio>
using namespace std;
main(){
	int I,i,j;
	for(;~scanf("%d",&I);puts("")){
		printf("1");
		vector<int> v(1);v[0]=1;
		for(i=2;i<=I;i++){
			vector<int>w;
			w.push_back(v[0]),printf(" %d",v[0]);
			for(j=0;j<v.size()-1;j++)w.push_back(v[j]+v[j+1]),printf(" %d",v[j]+v[j+1]);
			w.push_back(v[j]),printf(" %d",v[j]);
			v=w;
		}
	}
}