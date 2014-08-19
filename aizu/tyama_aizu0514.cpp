#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
main(){
	int a,b,c,n,x,y,z,w,i;
	for(;scanf("%d%d%d%d",&a,&b,&c,&n)>3;){
		vector<int>A(a,2);
		vector<int>B(b,2);
		vector<int>C(c,2);
		vector<tuple<int,int,int> >v;
		for(i=0;i<n;i++){
			scanf("%d%d%d%d",&x,&y,&z,&w);
			if(w)A[x-1]=B[y-1-a]=C[z-1-a-b]=1;
			else v.push_back(make_tuple(x-1,y-1-a,z-1-a-b));
		}
		for(i=0;i<v.size();i++){
			if(A[get<0>(v[i])]==1&&B[get<1>(v[i])]==1)C[get<2>(v[i])]=0;
			if(B[get<1>(v[i])]==1&&C[get<2>(v[i])]==1)A[get<0>(v[i])]=0;
			if(C[get<2>(v[i])]==1&&A[get<0>(v[i])]==1)B[get<1>(v[i])]=0;
		}
		for(i=0;i<A.size();i++)printf("%d\n",A[i]);
		for(i=0;i<B.size();i++)printf("%d\n",B[i]);
		for(i=0;i<C.size();i++)printf("%d\n",C[i]);
	}
}