#import<bitset>
main(){int N,q,l,r;scanf("%d%d",&N,&q);for(std::bitset<100000>x,y=~x>>100000-N,z;~scanf("%d%d%d",&q,&l,&r);)z=y>>N-r+l<<l,q&1?x^=z:printf("%d\n",(x&z).count());}