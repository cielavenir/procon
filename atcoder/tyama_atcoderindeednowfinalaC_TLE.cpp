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
	vector<tuple<int,int,int,int> >v(N+1);
	for(int i=0;i<N;i++){
		get<1>(v[i])=get();
		get<2>(v[i])=get();
		get<3>(v[i])=get();
		get<0>(v[i])=get();
	}
	sort(v.begin(),v.end());
#if 1
	for(int i=0;i<M;i++){
		int a,b,c;
		a=get(),b=get(),c=get();
		/*
		int lo=0,hi=N+1;
		for(;lo<hi+1;){
			int me=(lo+hi)/2;
			if(a>=get<1>(v[me])&&b>=get<2>(v[me])&&c>=get<3>(v[me])){
				lo=me;
			}else{
				hi=me;
			}
		}
		printf("%d\n",get<0>(v[lo]));
		*/
		for(int j=N;j>=0;j--)if(a>=get<1>(v[j])&&b>=get<2>(v[j])&&c>=get<3>(v[j])){
			printf("%d\n",get<0>(v[j]));
			break;
		}
	}
#else
	vector<tuple<int,int,int> >z(M);
	vector<int>r(M);
	for(int i=0;i<M;i++){
		get<0>(z[i])=get();
		get<1>(z[i])=get();
		get<2>(z[i])=get();
	}
	vector<thread> threads;
	for(int i=0;i<M;i++){
		threads.push_back(thread([i,N,&v,&z,&r]{
			for(int j=N;j>=0;j--)if(get<0>(z[i])>=get<1>(v[j])&&get<1>(z[i])>=get<2>(v[j])&&get<2>(z[i])>=get<3>(v[j])){
				r[i]=get<0>(v[j]);
				break;
			}
		}));
	}
	for(auto &t:threads)t.join();
	for(int i=0;i<M;i++)printf("%d\n",r[i]);
#endif
}

/*
2 1
0 200 200 5000
100 100 100 10000
100 100 100
*/