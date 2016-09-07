//http://codeforces.com/gym/100917
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

int main(){
	int N,W;
	scanf("%d%d",&N,&W);
	RMQ rmq(N);
	for(int i=1;i<=N;i++){
		int x;
		scanf("%d",&x);
		rmq.update(i,x+1);
	}
	for(int i=1;i<=N;i++){
		long long s=-1;
		for(int j=1;j<=N;j+=i)s+=rmq.query(j,min(j+i,N+1)).second;
		if(s<=W){
			printf("%d\n",i);
			break;
		}
	}
}