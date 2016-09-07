//http://codeforces.com/gym/100917
#include <vector>
#include <map>
#include <cstdio>
using namespace std;

int main(){
	int N,r=1;
	scanf("%d",&N);
	if(N==1){puts("0");return 0;}
	map<int,int>h;
	for(int q=2;q<N;q++){
		long long y=q;
		for(;;){
			y*=q;
			long long x=(y-1)/(q-1);
			if(x>N)break;
			h[x]+=1;
		}
	}
	for(int e=1;e<N;e++){
		if(N%e==0){
			r+=h[N/e];
			if(e!=1)r++;
		}
	}
	printf("%d\n",r);
}