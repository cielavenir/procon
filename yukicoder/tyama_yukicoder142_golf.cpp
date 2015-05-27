#import<vector>
#import<cstdio>
typedef unsigned long long ull;int main(){
int i=-1,N,S,T,U,L,Q,w=64;
scanf("%d%d%d%d%d%d",&N,&S,&T,&U,&L,&Q);
std::vector<ull>A(Q=(N+127)/w),B(Q);
for(;++i<N;S=((ull)S*T+U)%L)A[i/w]|=(ull)S%2<<i%w;
for(;~scanf("%d%d%d%d",&S,&T,&U,&L);){
for(T-=--S,--U,L=(T+63)/w,i=-1;++i<L;S%w&&(B[i]|=A[S/w+i+1]<<w-S%w))B[i]=A[S/w+i]>>S%w;
for((T%=w)&&(B[L-1]=B[L-1]<<w-T>>w-T);L--;U%w&&(A[U/w+L+1]^=B[L]>>w-U%w))A[U/w+L]^=B[L]<<U%w;
}for(i=-1;++i<N;)putchar(A[i/w]>>i%w&1?79:69);}