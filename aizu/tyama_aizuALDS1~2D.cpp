#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int cnt;

void insertionSort(vector<int> &a,int g){
	for(int i=g;i<a.size();i++){
		int v = a[i];
		int j = i - g;
		while(j>=0 && a[j]>v){
			a[j+g] = a[j];
			j = j - g;
			cnt++;
			a[j+g] = v;
		}
	}
}

void shellSort(vector<int> &a){
	vector<int>g;
	cnt = 0;
	for(int h=1;h<a.size();h=3*h+1)g.push_back(h);
	reverse(g.begin(),g.end());
	int m = g.size();
	printf("%d\n",m);
	for(int i=0;i<g.size();i++)printf(i<g.size()-1?"%d ":"%d\n",g[i]);
	for(int i=0;i<m;i++)insertionSort(a,g[i]);
}

int main(){
	vector<int> a;
	int n,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&x),a.push_back(x);
	shellSort(a);
	printf("%d\n",cnt);
	for(int i=0;i<n;i++)printf("%d\n",a[i]);
}