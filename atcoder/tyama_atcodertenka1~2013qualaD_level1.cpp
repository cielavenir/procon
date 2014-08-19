#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
const char *str;
string parse(int i,int rep){
	string s,x;
	int j=i,_j,k,c=0,cc;
	char *next;
	for(;;j++){
		if(str[j]=='('){
			if(++c==1)_j=j+1;
		}
		else if(str[j]==')'){
			if(--c==0){
				cc=strtol(str+j+1,&next,10);
				//x=parse(_j,cc);
				s+=parse(_j,cc);
				j=next-str-1;
			}
			if(c==-1)break;
		}else if(c==0){
			s+=str[j];
		}
	}
	x="";
	for(c=0;c<rep;c++)x+=s;
	return x;
}

main(){
	int b,l,n;
	string s;
	cin>>b>>l>>n>>s;
	s+=')';
	str=s.c_str();
	string r=parse(0,1);
	if(b<0)b=r.size()+b;
	cout<<r.substr(b,l)<<endl;
}