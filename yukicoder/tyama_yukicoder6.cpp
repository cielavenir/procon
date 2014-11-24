#include <vector>
#include <algorithm>
#include <cstdio>
#define M 200000
using namespace std;

int _hash(int n){
	for(;n>9;){
		int s=0;
		for(;n;n/=10)s+=n%10;
		n=s;
	}
	return n;
}
int table[M+1],p[M/2];
int main(){
	int i,j,n,m;
	table[0]=table[1]=1;
	for(i=2;i<=M;i++)if(!table[i])for(j=2*i;j<=M;j+=i)table[j]=1;
	scanf("%d%d",&n,&m);
	vector<int>lst;
	vector<int>lst_val;
	int result=0,result_max=0,result_val;
	for(i=n;i<=m;i++)if(!table[i]){
		int h=_hash(i);
		for(;find(lst.begin(),lst.end(),h)!=lst.end();result--){
			lst.erase(lst.begin());
			lst_val.erase(lst_val.begin());
		}
		lst.push_back(h);
		lst_val.push_back(i);
		result++;
		if(result_max<=result){
			result_max=result;
			result_val=lst_val[0];
		}
	}
	printf("%d\n",result_val);
}