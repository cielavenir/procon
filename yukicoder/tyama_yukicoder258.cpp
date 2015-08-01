#include <vector>
#include <cstdio>
#define BACK 2
int main(){
	int n;
	scanf("%d",&n);
	std::vector<int>v(n),prev(n);
	for(int i=0;i<n;i++){
		scanf("%d",&v[i]);
		int ma=0,_prev=-1;
		for(int j=0;j<=i-BACK;j++)if(ma<v[j])ma=v[j],_prev=j;
		v[i]+=ma;
		prev[i]=_prev;
	}
	int ma=0,idx;
	for(int i=n-BACK;i<n;i++)if(i>=0&&ma<v[i])ma=v[i],idx=i;
	printf("%d\n",ma);
	std::vector<int>bk;
	for(int i=idx;i>=0;i=prev[i])bk.push_back(i);
	for(int i=bk.size()-1;i>=0;i--)printf(i>0?"%d ":"%d\n",bk[i]+1);
}