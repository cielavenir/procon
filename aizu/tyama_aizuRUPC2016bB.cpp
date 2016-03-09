#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int D[3][2]={{1,0},{0,1},{-1,0}};
int main(){
	int W,H,N,d,r=0;
	scanf("%d%d%d",&W,&H,&N);
	vector<vector<int>> v={{W-1,H-1,W-1},{W-2,H-3,W-2}}, p={{0,0},{0,1}}, c={{0,0},{0,0}};
	for(;N--;){
		scanf("%d",&d);
		p[d][0]+=D[c[d][0]][0];
		p[d][1]+=D[c[d][0]][1];
		c[d][1]++;
		if(c[d][1]==v[d][c[d][0]])c[d][0]++,c[d][1]=0;
		if(abs(p[0][0]-p[1][0])+abs(p[0][1]-p[1][1])<2)r++;
	}
	printf("%d\n",r);
}