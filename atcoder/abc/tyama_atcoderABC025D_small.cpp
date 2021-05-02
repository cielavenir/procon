#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
const int H=5,W=5;
int m[H][W];
bool check(){
	for(int h=0;h<H;h++)for(int w=0;w<W-2;w++){
		if((m[h][w]<m[h][w+1]&&m[h][w+1]<m[h][w+2])||(m[h][w]>m[h][w+1]&&m[h][w+1]>m[h][w+2]))return false;
	}
	for(int h=0;h<H-2;h++)for(int w=0;w<W;w++){
		if((m[h][w]<m[h+1][w]&&m[h+1][w]<m[h+2][w])||(m[h][w]>m[h+1][w]&&m[h+1][w]>m[h+2][w]))return false;
	}
	return true;
}

int main(){
	vector<int>_lst(H*W+1);
	vector<int>area;
	for(int h=0;h<H;h++)for(int w=0;w<W;w++){
		scanf("%d",m[h]+w);
		if(m[h][w])_lst[m[h][w]]=1;
		else area.push_back(h*W+w);
	}
	vector<int>lst;
	for(int i=1;i<=H*W;i++)if(!_lst[i])lst.push_back(i);
	if(lst.empty()){
		puts(check()?"1":"0");
	}else{
		if(lst.size()>9)return 1;
		long long ret=0;
		do{
			for(int i=0;i<lst.size();i++){
				m[area[i]/W][area[i]%W]=lst[i];
			}
			ret+=check();
		}while(next_permutation(lst.begin(),lst.end()));
		printf("%lld\n",ret%1000000007);
	}
}