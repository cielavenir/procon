#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <numeric>
#include <algorithm>
#include <cstdio>
#define SIZ 26
using namespace std;
int A[SIZ],B[SIZ],C[SIZ];
unordered_set<long long>memo;
vector<int>V(SIZ);
bool dfs(int cur,int lA,int lB){
	if(cur==SIZ)return true;
	long long key=(long long)lA<<32|lB;
	if(memo.find(key)!=memo.end())return false;
	int a,b;
	int threshold_a=min(lA,A[V[cur]]);
	threshold_a=min(threshold_a,C[V[cur]]);
	int threshold_b=min(lB,B[V[cur]]);
	for(a=max(C[V[cur]]-threshold_b,0);a<=threshold_a;a++){
		b=C[V[cur]]-a;
		if(dfs(cur+1,lA-a,lB-b))return true;
	}
	memo.insert(key);
	return false;
}
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string Z;
	int l,i;
	getline(cin,Z);
	l=Z.size();
	for(i=0;i<l;i++)A[Z[i]-'A']++;
	getline(cin,Z);
	for(i=0;i<l;i++)B[Z[i]-'A']++;
	getline(cin,Z);
	for(i=0;i<l;i++)C[Z[i]-'A']++;
	for(i=0;i<SIZ;i++)if(A[i]+B[i]<C[i]){
		puts("NO");
		return 0;
	}
	iota(V.begin(),V.end(),0);
	sort(V.begin(),V.end(),[](const int &a,const int &b)->bool{return C[a]>C[b];});
	puts(dfs(0,l/2,l/2)?"YES":"NO");
	return 0;
}