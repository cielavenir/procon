#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int N,K;
	string S;
	cin>>N>>K>>S;
	vector<int>rooms(K);
	vector<int>num(N+1);
	vector<double>sum(N+1);
	vector<int>choose(N+1);
	vector<double>ret(N+1);
	for(int i=0;i<N;i++){
		if(S[i]=='1'){
			choose[i]=rooms[K-1];
			rooms[K-1]++;
		}else{
			auto it=upper_bound(rooms.begin(),rooms.end(),rooms[0]);
			it--;
			int idx=it-rooms.begin();
			choose[i]=rooms[idx];
			rooms[idx]++;
		}
	}
	for(int i=0;i<K;i++)num[rooms[i]]++;
	for(int i=0;i<=N;i++)sum[i]=num[i]*i;
	for(int i=N-1;i>=0;i--){
		ret[i]=sum[choose[i]+1]/num[choose[i]+1];
		sum[choose[i]+1]-=ret[i];
		sum[choose[i]]+=ret[i];
		num[choose[i]+1]--;
		num[choose[i]]++;
	}
	for(int i=0;i<N;i++)printf("%.9f\n",ret[i]);
}