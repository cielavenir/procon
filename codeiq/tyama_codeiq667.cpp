#include <bitset>
#include <cstdio>
#define N 100

int main(){
	std::bitset<N> bs; //0=tail, 1=head
	for(int i=2;i<=N;i++){
		//puts(bs.to_string().c_str());
		for(int j=i-1;j<N;j+=i)bs[j]=bs[j]^1;
	}
	//puts(bs.to_string().c_str());
	for(int i=0;i<N;i++)if(!bs[i])printf("%d,",i+1);
	puts("");
}

//これで済んでしまうとは。
//int main(){for(int i=1;i*i<=N;i++)printf("%d,",i*i);puts("");}