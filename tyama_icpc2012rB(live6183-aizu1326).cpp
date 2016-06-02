#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
int main(){
	int p,q;
	for(;cin>>p>>q,p;){
		vector<string>P(p),Q(q);
		vector<int>indent(p),a(q,-2);
		getline(cin,P[0]);
		for(int i=0;i<p;i++){
			getline(cin,P[i]);
			for(;P[i][indent[i]]=='.';indent[i]++);
		}
		for(int i=0;i<q;i++){
			getline(cin,Q[i]);
		}
		for(int R=1;R<21;R++)for(int C=1;C<21;C++)for(int S=1;S<21;S++){
			int k=0;
			auto f=[&](const string &s){
				for(auto &x:s){
					if(x=='(')k+=R;
					if(x==')')k-=R;
					if(x=='{')k+=C;
					if(x=='}')k-=C;
					if(x=='[')k+=S;
					if(x==']')k-=S;
				}
			};

			if(![&]{
				for(int i=0;i<p;i++){
					if(k!=indent[i])return false;
					f(P[i]);
				}
				return true;
			}())continue;
			k=0;
			for(int i=0;i<q;i++){
				if(a[i]==-2)a[i]=k;
				if(a[i]!=k)a[i]=-1;
				f(Q[i]);
			}
		}
		for(int i=0;i<a.size();i++)printf(i<a.size()-1?"%d ":"%d\n",a[i]);
	}
}