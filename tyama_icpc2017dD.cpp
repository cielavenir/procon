#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	int H,W;
	for(;~scanf("%d%d",&H,&W)&&H&&W;){
		vector<string>m(H);
		for(int h=0;h<H;h++)cin>>m[h];
		if(H*H<500){
			int R=0;
			for(int i=0;i<1<<H;i++){
				vector<short>v(W);
				int r=0;
				for(int j=0;j<H;j++)if(i>>j&1){
					r++;
					for(int w=0;w<W;w++)if(m[j][w]=='1')v[w]^=1;
				}
				if(all_of(v.begin(),v.end(),[](int e){return !e;}))R=max(R,r);
			}
			cout<<R<<endl;
		}else{
			vector<int>b(H);
			for(int h=0;h<H;h++){
				for(int w=0;w<W;w++)b[h]=(b[h]<<1)|(m[h][w]=='1');
			}
			vector<short>s(1<<W),t(1<<W);
			for(int w=1;w<1<<W;w++)s[w]=t[w]=-1;
			for(int h=0;h<H;h++){
				for(int w=0;w<1<<W;w++){
					if(s[w^b[h]]>=0)t[w]=max(s[w],short(1+s[w^b[h]]));
				}
				swap(s,t);
				t[0]=0;for(int w=1;w<1<<W;w++)t[w]=-1;
			}
			cout<<s[0]<<endl;
		}
	}
}
