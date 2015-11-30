#import<iostream>
#import<string>
#import<algorithm>
using namespace std;main(){string r,s;cin>>s;long long N=0,a=0,b,i,m=0,n=1,x;for(auto c:s)a=a*10+c-48,n*=10,N++;s="0123456789";do{for(i=-1,b=0;++i<N;b=b*10+s[i]-48);if(m<(x=min(abs(a-b),n-abs(a-b))))m=x,r=s;}while(next_permutation(s.begin(),s.end()));cout<<r.substr(0,N)<<endl;}