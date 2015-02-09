require'zlib'
IO.popen('g++ -xc++ -O2 -oZ - -lgmpxx -lgmp',?w){|io|io.puts Zlib.inflate'eNpNT0FuwjAQvPMKVxXIBoMSWqmHjfMDbogLilBkG+oocSI7qRwj/t5NC7Q+zHpnPOPdV2NlPSidmdb3TpdNPntSX2VdOleO/6hL04Ww+cxngzf2QmzZaN+VUhPfK+jHTit9Jg9fVrf4ZoL8AMb2ZCfS5H4+4EAifWdYFhcqW+t7gtdT4H/3kV3PraOT04iEV2CyLZjVik1sJRKosK+wj0ez3K6qQtBTOPraSE2R4FuesmJ5Gu9UxZFiBdv4oaFsvgOn+8FZEuHWlMZSdn3OS/bciZRLHmH6Sxqb53vYr9fArk0XT7IuvScKfgSZ5wrMmap8t06ZmgssuFbA7bhGgHBMChGO6QTbQmhsEd4Kkf6mY6yEIC408MA4xomUYZ5cpEwjq5EFKfRz7skU0axeRIKCXMr5jquHjSr0ocKiiJMCTrhlxHqT7dBnmcsybVUNt28lBJ5w'.unpack(?m)[0]}
IO.popen('./Z','r+'){|io|io.write $<.read;io.flush;puts io.read}
File.unlink(?Z)
__END__
#include<iostream>
#include<valarray>
#include<gmpxx.h>
using namespace std;typedef valarray<long long>V;int M=1000000007;V z(4);V &g(const V &_x,const V &_y){for(int i=0,j;i<2;i++)for(j=0;j<2;j++)z[i*2+j]=(_x[slice(i*2,2,1)]*_y[slice(j,2,2)]).sum()%M;return z;}main(){long long T,r=1,c,z;for(cin>>T;T--;){mpz_class d;cin>>c>>d;if(d>M-1)d%=M-1;V x(4),e(4);x[0]=x[1]=x[2]=e[0]=e[3]=1;for(c--;c;x=g(x,x),c>>=1)if(c&1)e=g(e,x);c=e.sum()%M;for(z=1;d!=0;c=c*c%M,d>>=1)if((d&1)!=0)z=z*c%M;r=r*z%M;}cout<<r<<endl;}