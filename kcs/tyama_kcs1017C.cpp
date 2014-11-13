#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int main(){
	int M,N,f=0,cM=0,cN=0;
	cin>>M;
	vector<pair<int,int> >m(M);
	for(int i=0;i<M;i++)cin>>m[i].first>>m[i].second;
	cin>>N;
	vector<pair<int,int> >n(N);
	for(int i=0;i<N;i++)cin>>n[i].first>>n[i].second;
	for(;;f^=1){
		if(!f){
			n[cN].first-=m[cM].second;
			if(n[cN].first<=0&&++cN==N){
				puts("kagamiz");
				break;
			}
		}else{
			m[cM].first-=n[cN].second;
			if(m[cM].first<=0&&++cM==M){
				puts("ringoh");
				break;
			}
		}
	}
}