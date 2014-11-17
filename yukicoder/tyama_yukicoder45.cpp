#include <vector>
#include <cstdio>
#define BACK 2
int main(){
	int n;
	scanf("%d",&n);
	std::vector<int>v(n);
	for(int i=0;i<n;i++){
		scanf("%d",&v[i]);
		int ma=0;
		for(int j=0;j<=i-BACK;j++)if(ma<v[j])ma=v[j];
		v[i]+=ma;
	}
	int ma=0;
	for(int i=n-BACK;i<n;i++)if(i>=0&&ma<v[i])ma=v[i];
	printf("%d\n",ma);
}