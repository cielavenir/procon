#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int M[1000][1440],C[1000],T[1000],X[1000];
vector<pair<int,int> >v;

void newday(){
	if(T[0]>=0)v.push_back(make_pair(T[0],1440));
	int i,p,t,u;
	for(p=1;p<1000;p++){
		if(C[p])for(t=T[p];t<1440;t++)M[p][t]=1;
	}
	for(i=0;i<v.size();i++){
		for(p=1;p<1000;p++){
			t=v[i].first,u=v[i].second;
			for(;t<u;t++)
				if(M[p][t])X[p]++;
		}
	}
	memset(M,0,sizeof(M));
	memset(C,0,sizeof(C));
	memset(T,0xff,sizeof(T));
	v.clear();
}

int main(){
	int n,M1,D1,M2,D2,h,m,s,p,q;char e;
	for(;scanf("%d",&n),n;){
		memset(M,0,sizeof(M));
		memset(C,0,sizeof(C));
		memset(T,0xff,sizeof(T));
		memset(X,0,sizeof(X));
		v.clear();
		for(M1=0;n;n--){
			scanf("%02d/%02d %02d:%02d %c %03d",&M2,&D2,&h,&m,&e,&p);
			if(M1!=M2||D1!=D2)newday(),M1=M2,D1=D2;
			s=e=='I'?1:0;
			h=h*60+m;
			if(T[p]==-1)T[p]=h;
			if(s)C[p]++;
			else{
				C[p]--;
				if(!C[p]){
					if(p==0)v.push_back(make_pair(T[0],h));
					else{
						//printf("---%d %d %d\n",p,T[p],h);
						for(q=T[p];q<h;q++)M[p][q]=1;
					}
					T[p]=-1;
				}
			}
		}
		newday();
		for(m=0,p=1;p<1000;p++){
			if(m<X[p])m=X[p];
		}
		printf("%d\n",m);
	}
}