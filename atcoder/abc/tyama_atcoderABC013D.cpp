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
	int n,m,d,i,x;
	scanf("%d%d%d",&n,&m,&d);
	vector<int> t(n),e(n),a(n);
	for(i=0;i<n;i++)t[i]=i,e[i]=i;
	for(i=0;i<m;i++)scanf("%d",&x),swap(t[x-1],t[x]);
	//mul(a,t)==e
	for(i=0;i<n;i++)a[t[i]]=i;
	//置換aのd乗を繰り返し二乗法により計算する
	for(;d;d>>=1){
		if(d&1)e=mul(e,a);
		a=mul(a,a);
	}
	for(i=0;i<n;i++)printf("%d\n",e[i]+1);
}