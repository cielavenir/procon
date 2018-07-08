#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int n,i,j;
	scanf("%d",&n);
	vector<int>x(1<<n),r(1<<n),m(1<<n);
	for(auto &e:x)scanf("%d",&e);
	for(i=0;i<1<<n;i++)for(j=i;j<1<<n;j=(j+1)|i){
		r[j]=max(r[j],x[i]+m[j]);
		m[j]=max(m[j],x[i]);
	}
	for(i=1;i<1<<n;i++)printf("%d\n",r[i]=max(r[i],r[i-1]));
}
