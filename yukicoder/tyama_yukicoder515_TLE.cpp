#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define INF (1<<29)
class RMQ{
	int size;
	vector<int> minval;
	int _query(int a,int b,int k,int l, int r){
		if(r<=a||b<=l)return INF;
		if(a<=l&&r<=b)return minval[k];
		else{
			int vl=_query(a,b,k*2+1,l,(l+r)/2);
			int vr=_query(a,b,k*2+2,(l+r)/2,r);
			return min(vl,vr);
		}
	}

public:
	RMQ(int k){init(k);}
	void init(int k){
		for(size=1;size<k;)size<<=1;
		//size=1<<(32-__builtin_clz(k));
		minval=vector<int>(2*size-1,INF);
	}

	void update(int k,int t){
		k+=size-1;
		minval[k]=t;
		while(k>0){
			k=(k-1)/2;
			minval[k]=min(minval[k*2+1],minval[k*2+2]);
		}
	}

	int query(int a,int b){
		return _query(a,b,0,0,size);
	}
};

int calc(const string &s,const string &t){
	int l=min(s.size(),t.size()),i=0;
	for(;i<l&&s[i]==t[i];i++);
	return i;
}
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N,I,J,M;
	long long X,D,R=0;
	cin>>N;
	vector<string>v(N);
	vector<int>tbl(N),rev(N);
	for(int i=0;i<N;i++)cin>>v[i],tbl[i]=i;
	cin>>M>>X>>D;
	sort(tbl.begin(),tbl.end(),[&](int i,int j)->bool{
		return v[i]<v[j];
	});
	for(int i=0;i<N;i++)rev[tbl[i]]=i;
	RMQ rmq(N);
	for(int i=0;i<N-1;i++)rmq.update(i+1,calc(v[tbl[i]],v[tbl[i+1]]));
	for(;M--;){
		I=X/~-N,J=X%~-N,X=(X+D)%((long long)N*~-N);
		if(I>J)swap(I,J);else ++J;
		int i=rev[I],j=rev[J];
		if(i>j)swap(i,j);
		R+=rmq.query(i+1,j+1);
	}
	cout<<R<<endl;
}
