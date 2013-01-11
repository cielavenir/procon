#include<iostream>
int main(){char s[256];int t,x,i;while(std::cin.getline(s,256)){for(t=i=0;s[i];){if(s[i]=='#')return 0;x=s[i]==' '?0:s[i]-'@';t+=x*++i;}std::cout<<t<<"\n";}}