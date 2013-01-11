//pku 2041
//std::string‚Ì‚ê‚ñ‚µ‚£‚Å‚µ‚ã

#include <iostream>
#include <algorithm>
#define between(n,x,m) (((n)<=(x))&&((x)<=(m)))

using namespace std;
string filter,str;

void J(){rotate(str.begin(),str.begin()+(str.length()-1),str.end());}
void C(){rotate(str.begin(),str.begin()+1,str.end());}
void E(){
  int i=(str.length())/2;
  string tmp=str;
  str.replace(0,i,tmp,str.length()-i,i);
  str.replace(str.length()-i,i,tmp,0,i);
}

void A(){reverse(str.begin(),str.end());}

void P(){
  int i=str.length();
  char *p=(char*)str.data();
  for(;i>=0;--i){
    if(between('0',p[i],'9')){
	  p[i]--;
	  if(p[i]=='/')p[i]='9';
	}
  }
}

void M(){
  int i=str.length();
  char *p=(char*)str.data();
  for(;i>=0;--i){
    if(between('0',p[i],'9')){
	  p[i]++;
	  if(p[i]==':')p[i]='0';
	}
  }
}


struct x{
  void operator()(char c){
    switch(c){
	  case 'J': J();break;
	  case 'C': C();break;
	  case 'E': E();break;
	  case 'A': A();break;
	  case 'P': P();break;
	  default:  M();break;
	}
  }
};

int main(){
  int n;
  cin >> n;
  while(n--){
    cin >> filter;
	cin >> str;
	for_each(filter.rbegin(), filter.rend(), x());
	cout << str << endl;
  }
  return 0;
}