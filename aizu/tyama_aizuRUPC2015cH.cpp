#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;
int main(){
	int N,H;
	cin>>N>>H;
	vector<pair<string,int> >v(N);
	for(int i=0;i<N;i++)cin>>v[i].first>>v[i].second;
	int ok=0,ng=0;
	for(int n=0,i=0;;){
		cout<<"? "<<v[n].first<<endl;
		string s;
		cin>>s;
		if((v[n].first[i]|32)==(s[0]|32)){
			++ok;
			v[n].first[i]='_';
			if(++i==v[n].first.size())i=0,++n;
		}else{
			++ng;
			if(--v[n].second<0){
				i=0,++n;
				if(!--H){
					cout<<"! Game Over"<<endl;
					return 0;
				}
			}
		}
		if(n==v.size())break;
	}
	int r=ok*1000/(ok+ng);
	cout<<"! Game Clear "<<r/10<<'.'<<r%10<<endl;
}