#include <unordered_map>
#include <cstdio>
#include <cstring>
using namespace std;
//char buf[9];
int main(){
	int N,K,i,j,k,x;
	scanf("%d%d",&N,&K);
	for(int i=10;i<N;i++){
		//sprintf(buf,"%d",i);
		unordered_map<int,int>m;
		//for(j=0;j<strlen(buf);j++)m[buf[j]]++;
		for(x=i;x;x/=10)m[x%10]++;
		for(k=2;k<=K;k++){
			//sprintf(buf,"%d",i*k);
			unordered_map<int,int>m0;
			//for(j=0;j<strlen(buf);j++)m0[buf[j]]++;
			for(x=i*k;x;x/=10)m0[x%10]++;
			if(m0!=m)break;
		}
		if(k>K)for(k=1;k<=K;k++)printf(k<K?"%d ":"%d\n",i*k);
	}
}
// 200000 6