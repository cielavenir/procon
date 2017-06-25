#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include <ctime>
#include <unistd.h>
using namespace std;

int main(){
	string bases="ATGC";
	string s,t;
	mt19937_64 engine((unsigned int)time(NULL)^(getpid()<<16));
	uniform_int_distribution<int>genchar(0,bases.size()-1);
	uniform_int_distribution<int>code(0,9);
	for(int i=0;i<1000;i++)s+=bases[genchar(engine)];
	t=s;
	for(int z=1000;z--;){
		int c=code(engine);
		if(c<6){
			uniform_int_distribution<int>area(0,t.size()-1);
			int idx=area(engine);
			t[idx]=bases[genchar(engine)];
		}else if(c<8){ //flip
			uniform_int_distribution<int>len(2,8);
			int l=len(engine);
			uniform_int_distribution<int>offset(0,t.size()-8);
			int idx=offset(engine);
			reverse(t.begin()+idx,t.begin()+idx+l);
		}else if(c<9){ //deletion
			uniform_int_distribution<int>len(1,8);
			int l=len(engine);
			uniform_int_distribution<int>offset(0,t.size()-8);
			int idx=offset(engine);
			t=t.substr(0,idx)+t.substr(idx+l);
		}else{ //insertion
			uniform_int_distribution<int>len(1,8);
			int l=len(engine);
			string x;
			for(int i=0;i<l;i++)x+=bases[genchar(engine)];
			uniform_int_distribution<int>offset(0,t.size());
			int idx=offset(engine);
			t=t.substr(0,idx)+x+t.substr(idx);
		}
	}
	cout<<s.size()<<' '<<t.size()<<endl;
	cout<<s<<endl;
	cout<<t<<endl;
}