#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <climits>
using namespace std;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

pair<string,string> alignment(const string &x,const string &y,bool flocal,int d,int e,int &score,const function<int(char,char)> &matcher){
	//Needleman-Wunsch-Gotoh
	//Smith-Waterman-Gotoh
	vector<vpii>M(x.size()+1,vpii(y.size()+1));
	vector<vpii>X(x.size()+1,vpii(y.size()+1));
	vector<vpii>Y(x.size()+1,vpii(y.size()+1));
	M[0][0]={0,-1};
	X[0][0]=Y[0][0]={flocal?0:INT_MIN/2,-1};
	for(int i=1;i<=x.size();i++){
		M[i][0]={flocal?0:INT_MIN/2,-1};
		X[i][0]={d+e*(i-1),1};
		Y[i][0]={flocal?0:INT_MIN/2,-1};
	}
	for(int j=1;j<=y.size();j++){
		M[0][j]={flocal?0:INT_MIN/2,-1};
		X[0][j]={flocal?0:INT_MIN/2,-1};
		Y[0][j]={d+e*(j-1),2};
	}
	pair<pii,int> result={{0,-1},-1};
	int curx=x.size(),cury=y.size();
	for(int i=1;i<=x.size();i++){
		for(int j=1;j<=y.size();j++){
			vpii Z={{M[i-1][j-1].first,0|8},{X[i-1][j-1].first,1},{Y[i-1][j-1].first,2}};
			M[i][j]=*max_element(Z.begin(),Z.end());
			M[i][j].first+=matcher(x[i-1],y[j-1]);
			M[i][j].second&=3;
			X[i][j]=max(pii({M[i-1][j].first+d,0|8}),max(pii({X[i-1][j].first+e,1}),pii({Y[i-1][j].first+d,2})));
			X[i][j].second&=3;
			Y[i][j]=max(pii({M[i][j-1].first+d,0|8}),max(pii({X[i][j-1].first+d,1}),pii({Y[i][j-1].first+e,2})));
			Y[i][j].second&=3;
			if(flocal){
				if(M[i][j].first<0)M[i][j]={0,-1};
				if(X[i][j].first<0)X[i][j]={0,-1};
				if(Y[i][j].first<0)Y[i][j]={0,-1};
				if(result.first<M[i][j])result={M[i][j],0|8},curx=i,cury=j;
				if(result.first<X[i][j])result={X[i][j],1},curx=i,cury=j;
				if(result.first<Y[i][j])result={Y[i][j],2},curx=i,cury=j;
			}
		}
	}
	if(!flocal){
		vector<pair<pii,int>> Z={{M[x.size()][y.size()],0|8},{X[x.size()][y.size()],1},{Y[x.size()][y.size()],2}};
		result=*max_element(Z.begin(),Z.end());
	}
	result.second&=3;
	score=result.first.first;

	//Backtrack
	int nxtmat=result.first.second,curmat=result.second;
	string a,b;
	for(;nxtmat>=0;){
		auto &MAT=nxtmat==0?M:nxtmat==1?X:Y;
		if(curmat==0){
			curx-=1;
			cury-=1;
			a+=x[curx];
			b+=y[cury];
		}else if(curmat==1){
			curx-=1;
			a+=x[curx];
			b+='-';
		}else if(curmat==2){
			cury-=1;
			a+='-';
			b+=y[cury];
		}
		curmat=nxtmat;
		nxtmat=MAT[curx][cury].second;
	}
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	return {a,b};
}
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s,t;
	cin>>s>>s>>s>>t;
	int score;
	//pair<string,string> res=alignment(s,t,false,-1,-1,score,[&](const char &a,const char &b)->int{return a==b ? 0 : -1;}); //medium
	pair<string,string> res=alignment(s,t,false,-9,-2,score,[&](const char &a,const char &b)->int{return a==b ? 0 : -5;}); //hard
	cout<<-score<<endl;
	cout<<res.first<<endl;
	cout<<res.second<<endl;
}