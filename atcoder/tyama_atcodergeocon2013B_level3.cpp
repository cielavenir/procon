#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
//#include <cassert>
using namespace std;
double H[99][99],D=1e8,d;
int main(){
	int N,i,j,x,y,P,M;
	vector<pair<int,int> >plus,minus;
	vector<int>idx;
	scanf("%d",&N);
	if(N>20)return 1;
	for(i=0;i<N;i++){
		scanf("%d%d",&x,&y);
		if(x<0)minus.push_back(make_pair(-x,y));
		else if(x>0)plus.push_back(make_pair(x,y));
	}
	if(minus.size()>plus.size())swap(plus,minus);
	//assert(plus.size()>=minus.size());
	P=plus.size(),M=minus.size();
	for(i=0;i<P;i++)idx.push_back(i);
if(M==0){
	for(D=i=0;i<P;i++)D+=plus[i].first;
}else{
	for(i=0;i<P;i++)for(j=0;j<M;j++)H[i][j]=min(
		hypot(plus[i].first-minus[j].first,plus[i].second-minus[j].second),
		(double)plus[i].first+minus[j].first
	);
	do{
		for(d=i=0;i<M;i++)d+=H[idx[i]][i];
		for(;i<P;i++)d+=plus[idx[i]].first;
		if(D>d)D=d;
		//next_partial_permutation: http://origin.googlecode.com/svn-history/r366/trunk/core/include/origin/algorithm/boost_combination.hpp
		//if(!M)break;
		reverse(idx.begin()+M,idx.end());
	}while(next_permutation(idx.begin(),idx.end()));
}
	printf("%f\n",D);
}