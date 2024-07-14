#include <vector>
#include <string>
#include <unordered_map>
#include <cstdio>
using namespace std;

string F(const vector<int> &v, int n){
	if(v.size()==0){
		if(n==0)return "";
		return "!";
	}
	if(v.size()==1){
		if(n==v[0])return "+";
		if(n==-v[0])return "-";
		return "!";
	}
	int a=v.size()/2,b=v.size()-a;
	unordered_map<int,string>m;
	for(int i=0;i<1<<a;i++){
		int x=0;
		string s;
		for(int j=0;j<a;j++){
			if(i&(1<<j)){x+=v[j];s+='+';}
			if(!(i&(1<<j))){x-=v[j];s+='-';}
		}
		m[x]=s;
	}
	for(int i=0;i<1<<b;i++){
		int x=0;
		string s;
		for(int j=0;j<b;j++){
			if(i&(1<<j)){x+=v[a+j];s+='+';}
			if(!(i&(1<<j))){x-=v[a+j];s+='-';}
		}
		auto it=m.find(n-x);
		if(it!=m.end())return it->second+s;
	}
	return "!";
}

int main(){
	int N,X,Y,t;
  scanf("%d%d%d",&N,&X,&Y);
	vector<int>v[2];
	for(int i=0;i<N;i++){
		scanf("%d",&t);
		v[i%2].push_back(t);
	}
  vector<string>r={F(v[0],Y),F(v[1],X)};
	if(r[0]=="!"||r[1]=="!"){
		puts("No");
	}else{
		puts("Yes");
		char pre='+';
		for(int i=0;i<N;i++){
			char cur=r[i%2][i/2];
			int x=pre==cur;
			putchar("RL"[x^(i%2)]);
			pre=cur;
		}
		putchar('\n');
	}
}
