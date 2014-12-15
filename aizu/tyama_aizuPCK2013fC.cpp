#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
const vector<string>unit={
	"","Man","Oku","Cho","Kei","Gai","Jo","Jou","Ko","Kan","Sei","Sai","Gok","Ggs","Asg","Nyt","Fks","Mts"
};
void print(__int128_t x,int d){
	if(d<unit.size()){
		print(x/10000,d+1);
		int v=x%10000;
		if(v)cout<<v<<unit[d];
	}
}
int main(){
	int _m,n;
	for(;scanf("%d%d",&_m,&n),_m;){
		__int128_t m=_m;
		for(;--n;)m*=_m;
		print(m,0);
		cout<<endl;
	}
}