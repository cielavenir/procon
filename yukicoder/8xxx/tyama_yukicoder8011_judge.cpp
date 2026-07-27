#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cstdio>
using namespace std;

int main(int argc,char **argv){
	if(argc<3){
		fprintf(stderr,"fas_judge in.txt out.txt\n");
		return 1;
	}
	int N,M;
	unordered_map<int,unordered_map<int,int> >m;
	{
		FILE *fin=fopen(argv[1],"rb");
		fscanf(fin,"%d%d",&N,&M);
		for(int i=0;i<M;i++){
			int a,b,c;
			fscanf(fin,"%d%d%d",&a,&b,&c);
			m[a][b]=c;
		}
		fclose(fin);
	}
	long long target;
	{
		FILE *fin=fopen(argv[2],"rb");
		fscanf(fin,"%lld",&target);
		fclose(fin);
	}

	//judge
	long long sum;
	if(scanf("%lld",&sum)==EOF)return -1; //format error.
	vector<int>order(N);
	vector<int>check(N);
	for(int i=0;i<N;i++){
		if(scanf("%d",&order[i])==EOF)return -1; //format error.
		if(check[order[i]])return -2; //duplicated order.
		check[order[i]]=1;
	}

	if(sum<target*4/5)return 1; //score is insufficient.

	long long s=0;
	for(int i=0;i<N-1;i++)for(int j=i+1;j<N;j++)s+=m[order[i]][order[j]];
	if(s!=sum)return 2; //score is invalid.
	return 0; //everything is ok.
}