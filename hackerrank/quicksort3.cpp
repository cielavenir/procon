#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

void quicksort(vector<int> &a, int L, int R) {
	if(L<R){
		int p=a[R];
		int l=L-1,r;
		for(;;){
			for(l++;l<R&&a[l]<=p;l++);
			for(r=l;r<R&&a[r]>p;r++);
			if(r>=R)break;
			swap(a[l],a[r]);
		}
		swap(a[l],a[R]);
		for(int i=0;i<a.size();i++)printf(i<a.size()-1?"%d ":"%d\n",a[i]);
		quicksort(a, L, l-1);
		quicksort(a, l+1, R);
	}
}
void quicksort(vector<int> &a) {
	quicksort(a, 0, a.size()-1);
}

int main(){
	int N;
	scanf("%d",&N);
	vector<int>v(N);
	for(int i=0;i<N;i++)scanf("%d",&v[i]);
	quicksort(v);
}