#include <cstdio>
#include <cassert>
#include <set>
using namespace std;
int D[4][2]={{1,1},{1,-1},{-1,1},{-1,-1}};
main(){
	int T,d,p,q,m,n;
	for(scanf("%d",&T);T;T--){
		set<pair<int,int> >s;
		scanf("%d%d",&p,&q);
		for(m=0;m*m<=p*p+q*q;m++)
			for(n=m?0:1;m*m+n*n<=p*p+q*q;n++)
				for(d=0;d<4;d++)
				if((D[d][0]*m*p+D[d][1]*n*q)%(m*m+n*n)==0 && (D[d][0]*m*q-D[d][1]*n*p)%(m*m+n*n)==0){
					s.insert(make_pair(D[d][0]*m,D[d][1]*n));
				}
		assert(s.size()>=8||s.size()==4);
		puts(s.size()==8?"P":"C");
	}
}