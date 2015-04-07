#include <vector>
#include <tuple>
#include <future>
#include <algorithm>
#include <cstdio>
using namespace std;

char Z[9999999];
int get(){
	static int input_count=0;
	int r=0;
	for(;'0'<=Z[input_count]&&Z[input_count]<='9';)r=r*10+Z[input_count++]-'0';
	input_count++;
	return r;
}

int main(){
	fread(Z,1,sizeof(Z),stdin);
	int N=get(),M=get();
	vector<int>cnt(N);
	vector<vector<int> >v(N);
	for(int i=0;i<M;i++){
		int a=get()-1,b=get()-1;
		cnt[a]++;
		v[b].push_back(a);
	}
	vector<double>r(N);
	for(int i=0;i<N;i++)r[i]=1;
	for(int C=1000;C--;){
		for(int i=0;i<N;i++){
			double s=0;
			for(auto &e:v[i])s+=r[e]/cnt[e];
			r[i]=0.1+0.9*s;
		}
	}
	for(auto &e:r)printf("%f\n",e);
}