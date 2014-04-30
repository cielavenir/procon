#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
int N;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main(int argc, char **argv){
	if(argc<2){
		printf("give me array size\n");
		return 1;
	}
	N=strtol(argv[1],NULL,10);
	int i,j;
	vector<int>v(N);
	for(i=0;i<N;i++){
		v[i]=i+1;
	}
	for(i=2;i<N-1;i++){ //N=3の場合はi=1にする必要がある
		for(j=i+1;j<N;j++){
			int g=gcd(v[i],v[j]);
			v[j]*=v[i]/g;
			v[i]=g;
		}
	}
	vector<int>ret;
	for(i=0;i<N;i++)if(v[i]<=N)ret.push_back(v[i]);
	sort(ret.begin(),ret.end());
	vector<int>::iterator it=unique(ret.begin(),ret.end());
	for(j=0;it!=ret.end();++it)j++;
	printf("%d\n",j); //12回
}