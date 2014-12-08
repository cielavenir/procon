#include <iostream>
#include <string>
#include <vector>
using namespace std;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main(){
	string s;
	for(;cin>>s;){
		if(s=="#")break;
		vector<string>v;
		for(int idx=0;idx<s.size();){
			if(s.substr(idx,4)=="west"){
				v.push_back("west");
				idx+=4;
			}else{
				v.push_back("north");
				idx+=5;
			}
		}

		int n=v.size()-1;
		int cur=1<<20;
		int numerator=cur;
		int d=v[n]=="west"?cur:0;
		for(n--,cur>>=1;n>=0;n--,cur>>=1){
			if(v[n]=="west"){
				d+=cur;
			}else{
				d-=cur;
			}
		}
		d*=90;
		int g=gcd(d,numerator);
		d/=g;numerator/=g;
		if(numerator==1){
			cout<<d<<endl;
		}else{
			cout<<d<<'/'<<numerator<<endl;
		}
	}
}