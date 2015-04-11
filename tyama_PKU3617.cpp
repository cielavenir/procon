#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
main(){
	int N,cnt=0;
	string s;
	cin>>N;
	vector<char>v;
	for(int i=0;i<N;i++){
		cin>>s;
		v.push_back(s[0]);
	}
	int a=0,b=N-1;
	for(;a<=b;){
		bool left=false;
		for(int i=0;a+i<=b;i++){
			if(v[a+i]<v[b-i]){left=true;break;}
			if(v[a+i]>v[b-i]){left=false;break;}
		}
		putchar(left ? v[a++] : v[b--]);
		if(++cnt==80)putchar('\n'),cnt=0;
	}
	if(cnt)putchar('\n');
}