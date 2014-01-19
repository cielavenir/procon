#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdio>
using namespace std;
char T[10][10000];
template<typename T> T max2(T head,T n){return max(n,head-n);}
int main(){
	int Y,X,i,j,r,y;
	for(;scanf("%d%d",&Y,&X),Y;printf("%d\n",r)){
		for(j=0;j<Y;j++)for(i=0;i<X;i++)scanf("%hhd",T[j]+i);

		vector<int> itx(X);iota(itx.begin(),itx.end(),0);
		vector<int> ity(Y);iota(ity.begin(),ity.end(),0);
		for(r=y=0;y<1<<Y;y++){
			r=max(r,accumulate(itx.begin(),itx.end(),0,[&](int s,int &i){
				return s+max2(Y,(int)count_if(ity.begin(),ity.end(),[&](int &j){return ((y>>j&1)==T[j][i]);}));
			}));
		}
	}
}