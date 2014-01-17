#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int N,d,t,q,i,j;
	for(;cin>>N,N;){
		int Q[25][25] = {{0}}; // Q[d][i] d 周期の i 時間目の量 (0<=i<d)
		for(i=0;i<N;++i){
			cin>>d>>t;
			for(j=0;j<d;++j){
				cin>>q;
				Q[d][(j+d-t)%d]+=q;
			}
		}
		const int L = 16*9*5*7*11;
		int sum = 0, T[L] = {0};
		for(d=1;d<=24;++d){
			if(d==13||d==17||d==19||d==23||d==1)
				sum+=*max_element(Q[d],Q[d]+d);
			else
				for(i=0;i<L;++i)T[i]+=Q[d][i%d];
		}
		cout << sum + *max_element(T,T+L) << endl;
	}
}