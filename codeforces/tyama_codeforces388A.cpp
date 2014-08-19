#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
 
int main(){
	int a,n,i=0,j,r=0;

	scanf("%d",&n);
	vector<int>v(n),pile(n);
	for(;i<n;i++)scanf("%d",&a),v[i]=a;
	sort(v.begin(),v.end());

	for(i=0;i<n;i++){
		int last=-1;
		a=0;
		for(j=0;j<r;j++){
			if(pile[j]>a&&v[i]>=pile[j]){
				last=j;
				a=pile[j];
			}
		}
		if(last<0)pile[r++]=1;
		else pile[last]++;
	}
	printf("%d\n",r);
}