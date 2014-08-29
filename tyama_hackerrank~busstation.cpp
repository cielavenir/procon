#include <vector>
#include <set>
#include <cstdio>
using namespace std;
bool check(vector<int>&v,int n){
	int s=0;
	for(int i=0;i<v.size();i++){
		s+=v[i];
		if(s>n)return false;
		if(s==n)s=0;
	}
	return s==0;
}
int main(){
	int N,S=0;
	scanf("%d",&N);
	vector<int>v(N);
	for(int i=0;i<N;i++){
		scanf("%d",&v[i]);
		S+=v[i];
	}
	set<int>result;
	for(int i=1;i*i<=S;i++){
		if(S%i==0){
			if(check(v,i))result.insert(i);
			if(check(v,S/i))result.insert(S/i);
		}
	}
	for(set<int>::iterator it=result.begin();it!=result.end();++it){
		if(it!=result.begin())printf(" ");
		printf("%d",*it);
	}
}