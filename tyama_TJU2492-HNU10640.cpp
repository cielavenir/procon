//Uncomment-out for HNU10640
#include <iostream>
#include <cstring>
using namespace std;
int main(){
  char s[9999],t[9999];
  int b,c,p,q,i;
  while(cin>>s>>b>>t>>c){
    p=q=0;
    //if(b==1)p=strlen(s)-1;else
    for(i=0;i<strlen(s);i++)p*=b,p+=s[i]-'0';
    //if(c==1)q=strlen(t)-1;else
    for(i=0;i<strlen(t);i++)q*=c,q+=t[i]-'0';
    cout << (p<q?'<':p>q?'>':'=') << endl;
  }
  return 0;
}