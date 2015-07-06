#include <vector>
#include <cstdio>
using namespace std;
#define M 1000000007
vector<vector<int> >pascal;
int f(int x,int y){return y?pascal[x+y-1][x]:!x;}
int main(){
	int A,B,C,D,R=0;
	scanf("%d%d%d%d",&C,&D,&A,&B);
	pascal.resize(C+D+1);
	for(int i=0;i<=C+D;i++){
		pascal[i].resize(i+1);
		pascal[i][0]=pascal[i][i]=1;
		for(int j=1;j<i;j++)pascal[i][j]=(pascal[i-1][j-1]+pascal[i-1][j])%M;
	}
	C-=A,D-=B;
	for(int i=0;i<=C;i++)for(int j=0;j<=D;j++){
		R=((long long)pascal[i+j][i]*f(C-i,B)%M*f(D-j,A)%M + R)%M;
	}
	printf("%d\n",(long long)R*pascal[A+B][A]%M);
}