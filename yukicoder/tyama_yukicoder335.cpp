#include <vector>
#include <map>
#include <cstdio>
using namespace std;
#define INF 9999999
class RMQ{
	int size;
	vector<int> minval;
	vector<int> maxval;
	pair<int,int> _query(int a,int b,int k,int l, int r){
		if(r<=a||b<=l)return make_pair(INF,-INF);
		if(a<=l&&r<=b)return make_pair(minval[k],maxval[k]);
		else{
			pair<int,int> vl=_query(a,b,k*2+1,l,(l+r)/2);
			pair<int,int> vr=_query(a,b,k*2+2,(l+r)/2,r);
			return make_pair(min(vl.first,vr.first),max(vl.second,vr.second));
		}
	}

public:
	RMQ(int k){init(k);}
	void init(int k){
		for(size=1;size<k;)size<<=1;
		//size=1<<(32-__builtin_clz(k));
		minval=vector<int>(2*size-1,INF);
		maxval=vector<int>(2*size-1,-INF);
	}

	void update(int k,int t){
		k+=size-1;
		minval[k]=maxval[k]=t;
		while(k>0){
			k=(k-1)/2;
			minval[k]=min(minval[k*2+1],minval[k*2+2]);
			maxval[k]=max(maxval[k*2+1],maxval[k*2+2]);
		}
	}

	pair<int,int> query(int a,int b){
		return _query(a,b,0,0,size);
	}
};

int main(){
	int N,M,R=0,r=0,r1;
	scanf("%d%d",&N,&M);
	for(int m=0;m<M;m++){
		map<int,int>idx;
		vector<int>v(N);
		RMQ rmq(N+1);
		for(int i=0;i<N;i++)scanf("%d",&v[i]),idx[v[i]]=i+1,rmq.update(i+1,v[i]);
		r1=0;
		for(int a=1;a<=N;a++)for(int b=1;b<=N;b++){
			int i=idx[a],j=idx[b],k=max(a,b);
			if(i<j){
				pair<int,int> x;
				int r0=0;
				if(1!=i){
					x=rmq.query(1,i);
					for(int e:{x.first,x.second})if((e-a)*(a-b)<0)r0=max(max(e,r0),k);
				}
				if(i+1!=j){
					x=rmq.query(i+1,j);
					for(int e:{x.first,x.second})if((a-e)*(e-b)<0)r0=max(max(e,r0),k);
				}
				if(j+1!=N+1){
					x=rmq.query(j+1,N+1);
					for(int e:{x.first,x.second})if((a-b)*(b-e)<0)r0=max(max(e,r0),k);
				}
				r1+=r0;
			}
		}
		if(r<r1)r=r1,R=m;
	}
	printf("%d\n",R);
}