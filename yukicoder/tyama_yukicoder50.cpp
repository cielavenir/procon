#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int main(){
	int N,M;
	scanf("%d",&N);
	vector<int>a(N);
	for(int i=0;i<N;i++)scanf("%d",&a[i]);
	scanf("%d",&M);
	vector<int>b(M);
	for(int i=0;i<M;i++)scanf("%d",&b[i]);
	sort(a.begin(),a.end());
	sort(b.begin(),b.end(),greater<int>());
	int result=M+1;
	do{
		int cur=0,s=0;
		for(int i=0;i<a.size();i++){
			for(;cur<b.size()&&s+a[i]>b[cur];s=0,cur++);
			if(cur==b.size())break;
			s+=a[i];
		}
		cur++;
		if(result>cur)result=cur;
	}while(next_permutation(a.begin(),a.end()));
	printf("%d\n",result>M?-1:result);
}