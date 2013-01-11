#include <vector>
#include <map>
#include <cstdio>

using namespace std;
vector<int> a;
int N,S,W,Q,g,i;

int hard(){
	int answer = 0, base = 1, sum = 0;
	map<int,int> freq;
	freq[0] = 1;

	for(i=a.size()-1; i>=0; i--){
		sum = (a[i]*base + sum) % Q;
		base = (base*10) % Q;

		if(a[i])answer += freq[sum];
		freq[sum] ++;
	}
	return answer;
}

int easy(){
	int answer = 0, nonZero = 0;
	for(i=0; i<a.size(); i++){
		nonZero += (a[i]!=0 ? 1 : 0);
		answer += (a[i]%Q==0 ? nonZero : 0);
	}
	return answer;
}

main(){for(;scanf("%d%d%d%d",&N,&S,&W,&Q),Q;printf("%d\n",(Q==2||Q==5)?easy():hard()))for(g=S,i=0,a.clear();i<N;g=(g>>1)^((g&1)?W:0),i++)a.push_back((g/7)%10);}