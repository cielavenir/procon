#include <vector>
#include <cstdio>
using namespace std;

int main(){
	int n,s=0;
	scanf("%d",&n);
	vector<int>v(n);
	for(int i=0;i<n;i++)scanf("%d",&v[i]),s+=v[i];
	if(s%2){
		puts("impossible");
		return 0;
	}
	vector<int>bag(s+1);
	bag[0]=1;
	for(int i=0;i<n;i++)for(int j=s;j>=v[i];j--)bag[j]|=bag[j-v[i]];
	puts(bag[s/2]?"possible":"impossible");
}