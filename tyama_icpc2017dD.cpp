#pragma GCC optimize("O3")
#pragma GCC target("avx")
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long parallel_type;
const int bit_width=8*sizeof(parallel_type);

int main(){
	int H,W;
	for(;~scanf("%d%d",&H,&W)&&H&&W;){
		vector<string>m(H);
		for(int h=0;h<H;h++)cin>>m[h];
		if(H<=21){
			vector<vector<parallel_type> >l(H);
			int parallel_width=(W+bit_width-1)/bit_width;
			for(int h=0;h<H;h++){
				l[h].resize(parallel_width);
				for(int w=0;w<W;w++)l[h][w/bit_width]|=parallel_type(m[h][w]=='1')<<(w%bit_width);
			}
			int R=0;
			for(int i=0;i<1<<H;i++){
				vector<parallel_type> v(parallel_width);
				int r=0;
				for(int j=0;j<H;j++)if(i>>j&1){
					r++;
					for(int k=0;k<parallel_width;k++)v[k]^=l[j][k];
				}
				if(none_of(v.begin(),v.end(),[](parallel_type e){return e;}))R=max(R,r);
			}
			cout<<R<<endl;
		}else{
			vector<int>b(H);
			for(int h=0;h<H;h++){
				for(int w=0;w<W;w++)b[h]=(b[h]<<1)|(m[h][w]=='1');
			}
			vector<short>s(1<<W),t(1<<W);
			for(int w=1;w<1<<W;w++)s[w]=-1;
			for(int h=0;h<H;h++){
				for(int w=0;w<1<<W;w++){
					t[w]=max(s[w],short(s[w^b[h]]>=0 ? 1+s[w^b[h]] : -1));
				}
				swap(s,t);
			}
			cout<<s[0]<<endl;
		}
	}
}
