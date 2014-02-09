#include <vector>
#include <map>
#include <cstdio>
using namespace std;

int main(){
	vector<int>item;
	map<int,int>bag1,bag2;
	int N,B,hN,i,j,s;
	scanf("%d%d",&N,&B);hN=N/2;
	item.resize(N);
	for(i=0;i<N;i++)scanf("%d",&item[i]);
	for(i=0;i<1<<hN;i++){
		for(j=s=0;j<hN;j++)if(i&(1<<j))s+=item[j];
		bag1[s]++;
	}
	for(i=0;i<1<<(N-hN);i++){
		for(j=s=0;j<(N-hN);j++)if(i&(1<<j))s+=item[j+hN];
		bag2[s]++;
	}
	s=0;
	for(map<int,int>::iterator it=bag1.begin();it!=bag1.end();++it){
		s+=it->second*bag2[B-it->first];
	}
	printf("%d\n",s);
}