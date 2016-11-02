#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
 
vector<int> mul(vector<int> &a,vector<int> &b){
	int i=0,n=a.size();
	vector<int> r(n);
	for(i=0;i<n;i++)r[i]=a[b[i]];
	return r;
}
 
int main(){
	int n,m,i,x,s;
	long long k;
	scanf("%d",&n);
	vector<int> t(n),e(n),a(n);
	for(i=0;i<n;i++)scanf("%d",&a[i]),t[i]=i,e[i]=i;
	for(i=n-1;i;i--)a[i]-=a[i-1];
	scanf("%d%lld",&m,&k);
	for(i=0;i<m;i++)scanf("%d",&x),swap(t[x-2],t[x-1]);
	//置換tのd乗を繰り返し二乗法により計算する
	for(;k;k>>=1){
		if(k&1)e=mul(e,t);
		t=mul(t,t);
	}
	for(k=a[i=0];i<n;i++)printf("%lld\n",k),k+=a[e[i]+1];
}
