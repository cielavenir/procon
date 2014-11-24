#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;

//derived from checkio expected-dice
//unfortunately TLE using Python, rewriting in C++11.

double expected(int n, int s, int t){//vector<int> b){
	//perform checkio probably-dice
	vector<double> a(s*(n+1)+1);
	for(int i=1;i<=s;i++)a[i+s]=pow(1.0/s,n);
	for(int e=0;e<n-1;e++)for(int i=s*n;i>=0;i--){
		double sum=0;
		for(int j=i;j<i+s;j++)sum+=a[j];
		a[i+s]=sum;
	}
	int l=t+1; //b.size();
	double ret=0;
	vector<double> p(l);
	p[0]=1;
	//vector<int> nxt(l);
	//for(int i=0;i<l;i++)nxt[i]=(i+b[i]+l)%l;
	for(int z=1;z<2000;z++){
		vector<double> pnxt(l);
		for(int x=0;x<l;x++)if(p[x]){
			for(int i=s+1;i<a.size();i++){
				int y=x+i-s;
				//y=nxt[y%l];
				if(y>=l)y=0;
				pnxt[y]+=p[x]*a[i];
			}
		}
		ret+=z*pnxt[t];
		pnxt[t]=0;
		p=pnxt;
	}
	return ret;
}

int main(){
	int N;
	scanf("%d",&N);
	printf("%f\n",expected(1,6,N));
}