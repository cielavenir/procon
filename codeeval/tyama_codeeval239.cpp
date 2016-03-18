#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

int cnt;
int partition(vector<int> &a,int p,int r){
	int i=p,j=r,k=a[p];
	for(;;){
		for(;a[i]<k;)i++;
		for(;a[j]>k;)j--;
		if(i>=j)return j;
		swap(a[i],a[j]);
	}
}
void quicksort(vector<int> &a,int p,int r){
	if(p<r){
		cnt++;
		int q=partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}
}
int main(int argc,char **argv){
	//freopen(argv[1],"r",stdin);
	string line;
	for(;getline(cin,line);){
		vector<int>a;
		int x;
		istringstream ss(line);
		for(;ss>>x;)a.push_back(x);
		cnt=0;
		quicksort(a,0,a.size()-1);
		printf("%d\n",cnt);
	}
}