#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
int main(){
	long long r=0;
	int N,L;
	cin>>N>>L;
	vector<pair<int,string> >v(N);
	for(int i=0;i<N;i++)cin>>v[i].first>>v[i].second;
	int start=0;
	//first L
	for(;start<v.size()&&v[start].second=="L";start++);
	for(int i=0;i<start;i++){
		r+=v[i].first-1-i;
	}
	//last R
	int end=v.size()-1;
	for(;end>=0&&v[end].second=="R";end--);
	end++;
	for(int i=v.size()-1,k=0;i>=end;i--,k++){
		r+=L-v[i].first-k;
	}

	int prev=start,cur=start,mid;
	for(;cur<end;prev=cur){
		for(;v[cur].second=="R";)cur++;
		mid=cur;
		for(;cur<end&&v[cur].second=="L";)cur++;
		int a,b;
		if(mid-prev<cur-mid)a=v[mid-1].first,b=a+1;
		else b=v[mid].first,a=b-1;

		for(int i=mid;i<cur;i++){ //dir L (right side)
			r+=v[i].first-b-(i-mid);
		}
		for(int i=mid-1,k=0;i>=prev;i--,k++){ //dir R (left side)
			r+=a-v[i].first-k;
		}
	}
	printf("%lld\n",r);
}