#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool solve(vector<string>_m,int H,int W,int N){
	int score=0,score_round=-1,cnt,color,i;
	for(int w=0;w<W;w++){
		i=H-1;
		for(int h=H-1;h>=0;h--)if(_m[h][w]!='.')_m[i][w]=_m[h][w],i--;
		for(;i>=0;i--)_m[i][w]='.';
	}
	for(;score_round;){
		vector<string>m=_m;
		score_round=0;
		for(int h=0;h<H;h++){
			cnt=1;
			color=-1; //-1=undefined,0=empty
			for(int w=0;w<W;w++){
				if(color==_m[h][w])cnt++;
				else{
					if(color!='.'&&cnt>=N)for(score_round+=cnt*color,i=w-cnt;i<w;i++)m[h][i]='.';
					cnt=1;
					color=_m[h][w];
				}
			}
			if(color!='.'&&cnt>=N)for(score_round+=cnt*color,i=W-cnt;i<W;i++)m[h][i]='.';
		}
		for(int w=0;w<W;w++){
			cnt=1;
			color=-1; //-1=undefined,0=empty
			for(int h=0;h<H;h++){
				if(color==_m[h][w])cnt++;
				else{
					if(color!='.'&&cnt>=N)for(score_round+=cnt*color,i=h-cnt;i<h;i++)m[i][w]='.';
					cnt=1;
					color=_m[h][w];
				}
			}
			if(color!='.'&&cnt>=N)for(score_round+=cnt*color,i=H-cnt;i<H;i++)m[i][w]='.';
		}
		for(int w=0;w<W;w++){
			i=H-1;
			for(int h=H-1;h>=0;h--)if(m[h][w]!='.')m[i][w]=m[h][w],i--;
			for(;i>=0;i--)m[i][w]='.';
		}
		score+=score_round;
		_m=m;
	}
	for(int i=0;i<H;i++){
		if(_m[i]!=string(W,'.'))return false;
	}
	return true;
}

int main(){
	int H,W,N;
	cin>>H>>W>>N;
	vector<string>m(H);
	for(int i=0;i<H;i++)cin>>m[i];
	for(int h=0;h<H;h++){
		for(int w=0;w<W-1;w++){
			swap(m[h][w],m[h][w+1]);
			if(solve(m,H,W,N)){
				cout<<"YES"<<endl;
				return 0;
			}
			swap(m[h][w],m[h][w+1]);
		}
	}
	cout<<"NO"<<endl;
	return 0;
}