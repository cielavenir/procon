#include <vector>
#include <cstdio>
using namespace std;

#define INF (1<<29)
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

#define M 100001
int A[M],S[M];
int main(){
	int R=INF;
	int n;
	scanf("%d",&n);
	vector<pair<int,int> >v(n);
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		v[i].first=x;
		v[i].second=y;
		A[x]+=1;
		A[y]-=1;
	}
	RMQ rmq(M);
	for(int j=1;j<M;j++){
		S[j]=A[j]+S[j-1];
		rmq.update(j,S[j]);
	}
	for(int i=0;i<n;i++){
		int r=rmq.query(v[i].first,v[i].second).second-1;
		r=max(r,rmq.query(1,v[i].first).second);
		r=max(r,rmq.query(v[i].second,M+1).second);
		if(R>r)R=r;
	}
	printf("%d\n",R);
}