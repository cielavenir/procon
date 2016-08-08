#include <cstdio>
#include <set>
main(){
	int t=1,T,a,b,l,L,n,m,r;
	for(scanf("%d",&T);t<=T;){
		scanf("%d%d",&a,&b);
		for(n=a,l=10;n/10;n/=10)l*=10;
		for(n=a,r=0;n<=b;n++){
			std::set<std::pair<int,int> >x;
			for(L=10;L<l;L*=10){
				m=(n%L)*(l/L)+n/L;
				if(n<m&&m<=b)x.insert(std::make_pair(n,m));
			}
			r+=x.size();
		}
		printf("Case #%d: %d\n",t++,r);
	}
}