#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
	int A,B,C;
	scanf("%d%d%d",&A,&B,&C);
	if(A+B+C>24)return 1;
	vector<pair<int,int> >v(A+B+C);
	for(int i=0;i<A;i++)v[C+i].first=1,scanf("%d",&v[C+i].second);
	for(int i=0;i<B;i++)v[C+A+i].first=2,scanf("%d",&v[C+A+i].second);
	sort(v.begin(),v.end());
	double x=0,y=0;
	do{
		double z=0;
		for(int i=0;i<A+B+C;i++){
			if(v[i].first==0)break;
			if(v[i].first==1)z+=v[i].second;
			if(v[i].first==2)z*=v[i].second;
		}
		x+=1;
		y+=z;
	}while(next_permutation(v.begin(),v.end()));
	printf("%.9f\n",y/x);
}