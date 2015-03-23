#include <vector>
#include <cstdio>
using namespace std;
int main(){
	int A,B;
	scanf("%d%d",&A,&B);
	vector<int>a(A);
	vector<int>b(B);
	for(int i=0;i<A;i++)scanf("%d",&a[i]);
	for(int i=0;i<B;i++)scanf("%d",&b[i]);
	vector<vector<int> >x(A+1),y(A+1);
	x[0].resize(B+1),y[0].resize(B+1);
	for(int i=1;i<=A;i++){
		x[i].resize(B+1),y[i].resize(B+1);
		y[i][0]=y[i-1][0]+a[A-i];
		x[i][0]=y[i][0]-x[i-1][0];
	}
	for(int i=0;i<=A;i++)for(int j=1;j<=B;j++){
		y[i][j]=y[i][j-1]+b[B-j];
		x[i][j]=y[i][j]-min(i?x[i-1][j]:1<<30,x[i][j-1]);
	}
	printf("%d\n",x[A][B]);
}