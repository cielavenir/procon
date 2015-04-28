#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
int main(){
	int N;
	double A;
	scanf("%d%lf",&N,&A);
	std::vector<int>v(N);
	for(int i=0;i<N;i++)scanf("%d",&v[i]);
	for(int i=0;i<N;i++){
		double r=0;
		for(int j=0;j<N;j++)if(i!=j)r+=pow(a,abs(v[i]-v[j]));
		printf("%f\n",r);
	}
}